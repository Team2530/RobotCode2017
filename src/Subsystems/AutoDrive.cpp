#include "../Robot.h"

double PIDAngleSource::PIDGet() {
	return Robot::tracker->GetCurrentAngle();
}

// Get the current displacement vector from current to goal
// and rotate it into the coordinate system of the PIDs
// (call with true/false for each component)
double coordAlongPath(bool alongx) {
	double angle = Robot::autodrive->GetCoordAngleRad();
	if (alongx) angle -= M_PI/2; // if y-axis is 0, x-axis is 90 deg = pi/2 rad
	// Ensure the position is most current
	Robot::tracker->UpdatePosition();
	double dx = Robot::autodrive->GetGoalPositionX() - Robot::tracker->GetCurrentPositionX();
	double dy = Robot::autodrive->GetGoalPositionY() - Robot::tracker->GetCurrentPositionY();
	Robot::tracker->table->PutNumber("dx", dx);
	Robot::tracker->table->PutNumber("dy", dy);
	return dy*cos(angle) + dx*sin(angle);
}

// Measures how far out the robot is from its target
double PIDParallelSource::PIDGet() {
	return coordAlongPath(false);
}

// Measures how far off the robot is from the path
double PIDPerpendicularSource::PIDGet() {
	return coordAlongPath(true);
}

AutoDrive::AutoDrive() :
	Subsystem("AutoDrive"),
	goalPositionX(0),
	goalPositionY(0),
	headingLockEnabled(false),
	pathAngleRad(0),
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
	//perpendicularPID(0.03, 0.0015, 0.0, &perpendicularS, &perpendicularO)
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

	// Set MAX_POW to default
	SetMaxPower();
	countStopsInRow=0;
}

void AutoDrive::InitDefaultCommand() {
}

void AutoDrive::UpdatePIDFromTable() {
	double scale = 100;
	/*
	double parallelP = DBtable->GetNumber("Slider 0", parallelPID.GetP()*scale)/scale;
	double parallelI = DBtable->GetNumber("Slider 1", parallelPID.GetI()*scale)/scale;
	double parallelD = DBtable->GetNumber("Slider 2", parallelPID.GetD()*scale)/scale;
	double perpendicularP = DBtable->GetNumber("Slider 3", perpendicularPID.GetP()*scale)/scale;
	double perpendicularI = perpendicularPID.GetI();
	double perpendicularD = perpendicularPID.GetD();
	/*/
	double parallelP = DBtable->GetNumber("Slider 0", parallelPID.GetP()*scale)/scale;
	double parallelI = parallelPID.GetI();
	double parallelD = parallelPID.GetD();
	double perpendicularP = DBtable->GetNumber("Slider 1", perpendicularPID.GetP()*scale)/scale;
	double perpendicularI = DBtable->GetNumber("Slider 2", perpendicularPID.GetI()*scale)/scale;
	double perpendicularD = DBtable->GetNumber("Slider 3", perpendicularPID.GetD()*scale)/scale;
	//*/
	parallelPID.SetPID(parallelP, parallelI, parallelD);
	perpendicularPID.SetPID(perpendicularP, perpendicularI, perpendicularD);
}

void AutoDrive::Set(double x, double y, double angle) {
	//UpdatePIDFromTable();
	this->goalPositionX = x;
	this->goalPositionY = y;
	double dx = x - Robot::tracker->GetCurrentPositionX();
	double dy = y - Robot::tracker->GetCurrentPositionY();
	pathAngleRad = atan2(dx, dy);
	Robot::tracker->table->PutNumber("path angle", GetCoordAngleDeg());
	Robot::tracker->table->PutNumber("goal angle", angle);
	anglePID.SetSetpoint(angle);
	anglePID.Enable();
	parallelPID.Enable();
	perpendicularPID.Enable();
	// Set at negative to make sure the robot moves before declaring it stopped
	countStopsInRow=-40;
}

void AutoDrive::MoveToPos(Position* pos) {
	// Ensure the position is most current
	Robot::tracker->UpdatePosition();
	double x = Robot::tracker->GetCurrentPositionX();
	double y = Robot::tracker->GetCurrentPositionY();
	double angle = Robot::tracker->GetCurrentAngle();
	pos->UpdatePositionAbs(&x, &y, &angle);
	Set(x, y, angle);
}

// Get the PID correction amount
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

double AutoDrive::GetGoalAngle() {
	return anglePID.GetSetpoint();
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
	bool isStopped=Robot::tracker->IsRobotStopped();
	//try
	if(isStopped){
		countStopsInRow ++;
		if (countStopsInRow > 5){
			return isStopped;
		}
	}
	else{
		countStopsInRow=0;
	}
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
	return correctPosition && correctHeading && isStopped;
}

// Reset each PID controller: this will disable them
// and set their outputs to 0, besides avoiding integral windup
void AutoDrive::PIDDisable() {
	anglePID.Reset();
	parallelPID.Reset();
	perpendicularPID.Reset();
}

const double MAX_ROT = 0.5;

void AutoDrive::SetMaxPower(double pow) {
	MAX_POW = pow;
}

double clamp(double value, double max) {
	if (value > max) return max;
	if (value < -max) return -max;
	return value;
}

void AutoDrive::Drive(DriveTrain* drivetrain) {
	double x = clamp(perpendicularC, MAX_POW);
	double y = clamp(parallelC, MAX_POW);
	double rot = clamp(angleC, MAX_ROT);

	// Rotate coordinates to robot oriented
	// Take into account the angle between field oriented and robot oriented
	// And between field oriented and relative to our path
	double angle = Robot::tracker->GetCurrentAngle() - Robot::autodrive->GetCoordAngleDeg();

	drivetrain->DirectDrive(
		x, y, rot, angle
	);
}

void AutoDrive::EnableHeadingLock(bool enabled) {
	// If the joystick is twisted, use that value for control
	if (!enabled) {
		if (headingLockEnabled) {
			// Stop updating PID values
			anglePID.Reset();
			//std::printf("Disable heading lock\n");
			// Unset this flag to avoid disabling the PID again
			headingLockEnabled = false;
		}
		return;
	}
	// Enable PID locked to the current angle
	if (!headingLockEnabled) {
		double angle = Robot::tracker->GetCurrentAngle();
		// Set PID to maintain current angle
		anglePID.SetSetpoint(angle);
		Robot::tracker->table->PutNumber("goal angle", angle);
		//std::printf("Lock to heading %f\n", currentAngle);
		// Enable PID to update angleC value
		anglePID.Enable();
		// Set this flag to avoid re-enabling the PID every time
		headingLockEnabled = true;
	}
}
