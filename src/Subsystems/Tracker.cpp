#include "../Commands/GetFieldPosition.h"
#include "Tracker.h"
#include "../RobotMap.h"


#include "../Robot.h"

Tracker::Tracker() :
	Subsystem("TrackerSubsystem"),
	pidrs(&this->currentAngle),
	pidro(&this->pidr),
	pidpo(&this->power),
	pidpc(0.01, 0.0001, 0.0, this, &pidpo),
	pidrc(0.01, 0.0001, 0.0, &pidrs, &pidro)
{
	frontEncoder = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );//0,1 gonna change: encoder wires
	sideEncoder = new frc::Encoder(8,9,false, Encoder::CounterBase::k2X );//0,1 gonna change ^^
	frontEncoder->SetDistancePerPulse(0.012566/2);//encoderticks/revolution * dpi = 1/1000 * 4pi : ticks/rev = 1/1000 d = 4 pi = 3.14
	sideEncoder->SetDistancePerPulse(0.012566/2); //^^
	pidpc.SetTolerance(1.0); // inches
	pidpc.SetSetpoint(0);
	pidrc.SetTolerance(5.0); // degrees
	ahrs = new AHRS(SerialPort::kMXP);//check port
	table = NetworkTable::GetTable("robotPosition");
}
void Tracker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	frontEncoder->Reset();
	sideEncoder->Reset();
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::StartTracking(){
	currentPositionX = Robot::initialX;
	currentPositionY = 17.25;
	currentAngle = 0;
}

void Tracker::GetPosition(){
	if (ahrs == nullptr) {
		ahrs = Robot::oi->GetAHRS();
	}
	double distanceX = sideEncoder->GetDistance();
	double distanceY = frontEncoder->GetDistance();
	double angle =  ahrs->GetAngle();
	double rad = angle * M_PI / 180;
	double changeInX = cos(rad) * distanceX + sin(rad) * distanceY;
	double changeInY = cos(rad) * distanceY - sin(rad) * distanceX;
	currentPositionX += changeInX;
	currentPositionY += changeInY;
	currentAngle = angle;
	frontEncoder->Reset();
	sideEncoder->Reset();
	table->PutNumber("x", currentPositionX);;
	table->PutNumber("y", currentPositionY);;
	table->PutNumber("angle", currentAngle);
}

void Tracker::RotateTo(double angle) {
	pidrc.SetSetpoint(angle);
	goalPositionX = currentPositionX;
	goalPositionY = currentPositionY;
}
void Tracker::RotateBy(double deltaAngle) {
	double angle = currentAngle + deltaAngle;
	RotateTo(angle);
}

void Tracker::MoveToRel(double forward, double right) {
	double x = currentPositionX + right;
	double y = currentPositionY + forward;
	MoveToAbs(x, y);
}

void Tracker::MoveToAbs(double x, double y) {
	this->goalPositionX = x;
	this->goalPositionY = y;
	pidrc.SetSetpoint(currentAngle); // make sure we stay aligned while moving
	//pidrc.Enable();
	pidpc.Enable();
}

double Tracker::GetPIDRotation() {
	return pidr;
}

double Tracker::GetDistance() {
	double dx = this->goalPositionX - this->currentPositionX;
	double dy = this->goalPositionY - this->currentPositionY;
	return hypot(dx,dy);
}
double Tracker::PIDGet() {
	return GetDistance();
}

bool Tracker::PIDFinished() {
	return pidpc.OnTarget() && pidrc.OnTarget();
}

void Tracker::PIDReset() {
	pidpc.Reset();
	pidrc.Reset();
}

void Tracker::Drive(DriveTrain* drivetrain) {
	double dx = goalPositionX - currentPositionX;
	double dy = goalPositionY - currentPositionY;
	double goalAngle = atan2(dy, dx) * 180 / M_PI;
	double backward = -power;
	if (backward > 0.4) backward = 0.4;
	if (backward < -0.4) backward = -0.4;
	double rot = pidr;
	if (rot > 0.3) rot = 0.3;
	if (rot < -0.3) rot = -0.3;
	drivetrain->DriveWithCoordinates(
		0, backward, rot,
		currentAngle - goalAngle
	);
}

double Tracker::GetCurrentPositionX(){
	return currentPositionX;
}
double Tracker::GetCurrentPositionY(){
	return currentPositionY;
}
