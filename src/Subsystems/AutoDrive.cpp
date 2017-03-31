#include "AutoDrive.h"
#include "../Robot.h"

AutoDrive::AutoDrive() :
	Subsystem("AutoDrive"),
	pidrs(&Robot::tracker->currentAngle),
	pidro(&this->pidr),
	pidpo(&this->power),
	pidpc(0.04, 0.000, 0.12, this, &pidpo),
	pidrc(0.02, 0.000, 0.04, &pidrs, &pidro)
{
	MAX_POW = 0.75;

	pidpc.SetAbsoluteTolerance(2.0); // inches
	pidpc.SetSetpoint(0);
	//pidpc.SetOutputRange(0, 1);

	pidrc.SetInputRange(-180, 180);
	pidrc.SetAbsoluteTolerance(2); // degrees
	pidrc.SetContinuous();
	pidrc.SetOutputRange(-1, 1);

	SDtable = NetworkTable::GetTable("SmartDashboard");
	DBtable = SDtable->GetSubTable("DB");
}

void AutoDrive::InitDefaultCommand() {

}

void AutoDrive::UpdatePIDFromTable() {
	double scale = 50;
	double Pdist = DBtable->GetNumber("Slider 0", pidpc.GetP()*scale)/scale;
	double Ddist = DBtable->GetNumber("Slider 1", pidpc.GetD()*scale)/scale;
	double Prot = DBtable->GetNumber("Slider 2", pidrc.GetP()*scale)/scale;
	double Drot = DBtable->GetNumber("Slider 3", pidrc.GetD()*scale)/scale;
	pidpc.SetPID(Pdist, pidpc.GetI(), Ddist);
	pidrc.SetPID(Prot, pidrc.GetI(), Drot);
}

void AutoDrive::Set(double x, double y, double angle) {
	//UpdatePIDFromTable();
	this->goalPositionX = x;
	this->goalPositionY = y;
	pidrc.SetSetpoint(angle);
	pidrc.Enable();
	pidpc.Enable();
}

void AutoDrive::MoveToPos(Position* pos) {
	double x = Robot::tracker->GetCurrentPositionX();
	double y = Robot::tracker->GetCurrentPositionY();
	double angle = Robot::tracker->GetCurrentAngle();
	pos->UpdatePositionAbs(&x, &y, &angle);
	Set(x, y, angle);
}

double AutoDrive::GetPIDRotation() {
	return pidr;
}

double AutoDrive::GetDistance() {
	Robot::tracker->UpdatePosition();
	double dx = this->goalPositionX - Robot::tracker->GetCurrentPositionX();
	double dy = this->goalPositionY - Robot::tracker->GetCurrentPositionY();
	double distance = hypot(dx,dy);
	//std::printf("Distance: %f\n", distance);
	return distance;
}
double AutoDrive::PIDGet() {
	return GetDistance();
}

bool AutoDrive::PIDFinished() {
	bool correctPosition = pidpc.OnTarget();
	bool correctHeading = pidrc.OnTarget();
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
	return correctPosition && correctHeading;
}

void AutoDrive::PIDReset() {
	pidpc.Reset();
	pidrc.Reset();
}

void AutoDrive::PIDDisable() {
	pidpc.Disable();
	pidrc.Disable();
}

const double MAX_ROT = 0.5;

void AutoDrive::SetMaxPower(double pow) {
	MAX_POW = pow;
}

void AutoDrive::Drive(DriveTrain* drivetrain) {
	double dx = goalPositionX - Robot::tracker->GetCurrentPositionX();
	double dy = goalPositionY - Robot::tracker->GetCurrentPositionY();
	double goalAngle = atan2(dx, dy) * 180 / M_PI;
	double pwr = power;
	if (pwr > MAX_POW) pwr = MAX_POW;
	if (pwr < -MAX_POW) pwr = -MAX_POW;
	double rot = pidr;
	if (rot > MAX_ROT) rot = MAX_ROT;
	if (rot < -MAX_ROT) rot = -MAX_ROT;
	//std::printf("Drive command: %f\n", backward);

	// Rotate coordinates to robot oriented
	double rad = (goalAngle - Robot::tracker->GetCurrentAngle() + 90) * M_PI/180;
	double x = pwr*cos(rad);
	double y = pwr*sin(rad);

	drivetrain->DirectDrive(
		x, y, rot
	);
}

void AutoDrive::EnableHeadingLock(bool enabled) {
	// If the joystick is twisted, use that value for control
	if (!enabled) {
		if (headingLockEnabled) {
			pidrc.Disable();
			//std::printf("Disable heading lock\n");
			headingLockEnabled = false;
		}
		return;
	}
	// Enable PID is locked to the current angle and enabled
	if (!headingLockEnabled) {
		Robot::tracker->UpdatePosition();
		pidr = 0; // reset PID output to 0, just in case
		pidrc.Reset();
		pidrc.SetSetpoint(Robot::tracker->GetCurrentAngle());
		//std::printf("Lock to heading %f\n", currentAngle);
		pidrc.Enable();
		headingLockEnabled = true;
		return;
	}
}
