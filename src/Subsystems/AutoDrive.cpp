#include "AutoDrive.h"
#include "../Robot.h"

double PIDAngleSource::PIDGet() {
	return Robot::tracker->GetCurrentAngle();
}

double coordAlongPath(bool alongx) {
	double angle = Robot::autodrive->GetCoordAngleRad();
	if (alongx) angle += M_PI/2; // if y-axis is 0, x-axis is 90 deg = pi/2 rad
	double dx = Robot::autodrive->GetGoalPositionX() - Robot::tracker->GetCurrentPositionX();
	double dy = Robot::autodrive->GetGoalPositionY() - Robot::tracker->GetCurrentPositionY();
	return dy*cos(angle) + dx*sin(angle);
}

double PIDParallelSource::PIDGet() {
	return coordAlongPath(false);
}

double PIDPerpendicularSource::PIDGet() {
	return coordAlongPath(true);
}

AutoDrive::AutoDrive() :
	Subsystem("AutoDrive"),
	goalPositionX(0),
	goalPositionY(0),
	headingLockEnabled(false),
	pathAngleRad(0),
	MAX_POW(0.75),
	angleC(0),
	parallelC(0),
	perpendicularC(0),
	angleS(),
	parallelS(),
	perpendicularS(),
	angleO(&this->angleC),
	parallelO(&this->parallelC),
	perpendicularO(&this->perpendicularC),
	anglePID(0.02, 0.000, 0.04, &angleS, &angleO),
	parallelPID(0.04, 0.000, 0.12, &parallelS, &parallelO),
	perpendicularPID(0.04, 0.000, 0.12, &perpendicularS, &perpendicularO)
{
	parallelPID.SetAbsoluteTolerance(2.0); // inches
	parallelPID.SetSetpoint(0);
	parallelPID.SetOutputRange(-1, 1);
	perpendicularPID.SetAbsoluteTolerance(2.0); // inches
	perpendicularPID.SetSetpoint(0);
	perpendicularPID.SetOutputRange(-1, 1);

	anglePID.SetInputRange(-180, 180);
	anglePID.SetAbsoluteTolerance(2); // degrees
	anglePID.SetContinuous();
	anglePID.SetOutputRange(-1, 1);

	SDtable = NetworkTable::GetTable("SmartDashboard");
	DBtable = SDtable->GetSubTable("DB");
}

void AutoDrive::InitDefaultCommand() {

}

void AutoDrive::UpdatePIDFromTable() {
	double scale = 50;
	double Pdist = DBtable->GetNumber("Slider 0", parallelPID.GetP()*scale)/scale;
	double Ddist = DBtable->GetNumber("Slider 1", parallelPID.GetD()*scale)/scale;
	double Prot = DBtable->GetNumber("Slider 2", anglePID.GetP()*scale)/scale;
	double Drot = DBtable->GetNumber("Slider 3", anglePID.GetD()*scale)/scale;
	parallelPID.SetPID(Pdist, parallelPID.GetI(), Ddist);
	anglePID.SetPID(Prot, anglePID.GetI(), Drot);
}

void AutoDrive::Set(double x, double y, double angle) {
	//UpdatePIDFromTable();
	this->goalPositionX = x;
	this->goalPositionY = y;
	double dx = x - Robot::tracker->GetCurrentPositionX();
	double dy = y - Robot::tracker->GetCurrentPositionY();
	pathAngleRad = atan2(dx, dy);
	anglePID.SetSetpoint(angle);
	anglePID.Enable();
	parallelPID.Enable();
	perpendicularPID.Enable();
}

void AutoDrive::MoveToPos(Position* pos) {
	double x = Robot::tracker->GetCurrentPositionX();
	double y = Robot::tracker->GetCurrentPositionY();
	double angle = Robot::tracker->GetCurrentAngle();
	pos->UpdatePositionAbs(&x, &y, &angle);
	Set(x, y, angle);
}

double AutoDrive::GetPIDRotation() {
	return angleC;
}

double AutoDrive::GetDistance() {
	Robot::tracker->UpdatePosition();
	double dx = this->goalPositionX - Robot::tracker->GetCurrentPositionX();
	double dy = this->goalPositionY - Robot::tracker->GetCurrentPositionY();
	double distance = hypot(dx,dy);
	//std::printf("Distance: %f\n", distance);
	return distance;
}

double AutoDrive::GetGoalPositionX() {
	return goalPositionX;
}

double AutoDrive::GetGoalPositionY() {
	return goalPositionY;
}

double AutoDrive::GetCoordAngleRad() {
	return pathAngleRad;
}

double AutoDrive::GetCoordAngleDeg() {
	return pathAngleRad * 180/M_PI;
}

bool AutoDrive::PIDFinished() {
	bool correctPosition = parallelPID.OnTarget() && perpendicularPID.OnTarget();
	bool correctHeading = anglePID.OnTarget();
	/*
	if (correctPosition && !correctHeading) {
		double goal = pidrc.GetSetpoint();
		double deviation = goal - Robot::tracker->GetCurrentAngle();
		std::printf("Waiting to rotate (%f deg away)\n", deviation);
		//if (fabs(deviation) < 1) return true;
	} else if (correctHeading && !correctPosition) {
		double dx = this->goalPositionX - Robot::tracker->GetCurrentPositionX();
		double dy = this->goalPositionY - Robot::tracker->GetCurrentPositionY();
		double distance = hypot(dx,dy);
		std::printf("Waiting to move (%f in away)\n", distance);
		//if (distance < 0.1) return true;
	}
	*/
	return correctPosition && correctHeading;
}

void AutoDrive::PIDReset() {
	anglePID.Reset();
	parallelPID.Reset();
	perpendicularPID.Reset();
}

void AutoDrive::PIDDisable() {
	anglePID.Disable();
	parallelPID.Disable();
	perpendicularPID.Disable();
}

const double MAX_ROT = 0.5;

void AutoDrive::SetMaxPower(double pow) {
	MAX_POW = pow;
}

void AutoDrive::Drive(DriveTrain* drivetrain) {
	double x = perpendicularC;
	if (x > MAX_POW) x = MAX_POW;
	if (x < -MAX_POW) x = -MAX_POW;
	double y = parallelC;
	if (y > MAX_POW) y = MAX_POW;
	if (y < -MAX_POW) y = -MAX_POW;
	double rot = angleC;
	if (rot > MAX_ROT) rot = MAX_ROT;
	if (rot < -MAX_ROT) rot = -MAX_ROT;

	// Rotate coordinates to robot oriented
	double angle = Robot::tracker->GetCurrentAngle() + Robot::autodrive->GetCoordAngleDeg();

	drivetrain->DirectDrive(
		x, y, rot, angle
	);
}

void AutoDrive::EnableHeadingLock(bool enabled) {
	// If the joystick is twisted, use that value for control
	if (!enabled) {
		if (headingLockEnabled) {
			anglePID.Disable();
			//std::printf("Disable heading lock\n");
			headingLockEnabled = false;
		}
		return;
	}
	// Enable PID is locked to the current angle and enabled
	if (!headingLockEnabled) {
		Robot::tracker->UpdatePosition();
		angleC = 0; // reset PID output to 0, just in case
		anglePID.Reset();
		anglePID.SetSetpoint(Robot::tracker->GetCurrentAngle());
		//std::printf("Lock to heading %f\n", currentAngle);
		anglePID.Enable();
		headingLockEnabled = true;
		return;
	}
}
