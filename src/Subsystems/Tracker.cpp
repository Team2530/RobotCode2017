#include "../Commands/GetFieldPosition.h"
#include "Tracker.h"
#include "../RobotMap.h"


#include "../Robot.h"

Tracker::Tracker() :
	Subsystem("TrackerSubsystem"),
	pidrs(&this->currentAngle),
	pidro(&this->pidr),
	pidpo(&this->power),
	pidpc(0.01, 0.000, 0.0, this, &pidpo),
	pidrc(0.01, 0.000, 0.0, &pidrs, &pidro)
{
	frontEncoder = new frc::Encoder(8,9,false, Encoder::CounterBase::k2X );//0,1 gonna change: encoder wires
	sideEncoder = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );//0,1 gonna change ^^
	frontEncoder->SetDistancePerPulse(0.012566/2);//encoderticks/revolution * dpi = 1/1000 * 4pi : ticks/rev = 1/1000 d = 4 pi = 3.14
	sideEncoder->SetDistancePerPulse(-0.012566/2); //^^

	pidpc.SetAbsoluteTolerance(1.0); // inches
	pidpc.SetSetpoint(0);
	pidpc.SetOutputRange(0, 1);

	pidrc.SetInputRange(0, 360);
	pidrc.SetAbsoluteTolerance(5.0); // degrees
	pidrc.SetContinuous();
	pidrc.SetOutputRange(-1, 1);

	ahrs = nullptr; // new AHRS(SerialPort::kMXP);//check port
	table = NetworkTable::GetTable("robotPosition");
	SDtable = NetworkTable::GetTable("SmartDashboard");
	DBtable = SDtable->GetSubTable("DB");
}
void Tracker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	frontEncoder->Reset();
	sideEncoder->Reset();
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::StartTracking(){
	//currentPositionX = Robot::initialX;
	//currentPositionY = 17.25;
	currentPositionX = 0;
	currentPositionY = 0;
	currentAngle = 0;
	if (ahrs == nullptr) {
		ahrs = Robot::oi->GetAHRS();
	}
	if (ahrs != nullptr) ahrs->Reset();
}

void Tracker::GetPosition(){
	if (ahrs == nullptr) {
		ahrs = Robot::oi->GetAHRS();
	}
	double distanceX = sideEncoder->GetDistance();
	double distanceY = frontEncoder->GetDistance();
	frontEncoder->Reset();
	sideEncoder->Reset();
	double angle =  ahrs != nullptr ? ahrs->GetYaw() : 0.0;
	double rad = angle * M_PI / 180;
	double changeInX = cos(rad) * distanceX + sin(rad) * distanceY;
	double changeInY = cos(rad) * distanceY - sin(rad) * distanceX;
	currentPositionX += changeInX;
	currentPositionY += changeInY;
	currentAngle = angle;
	table->PutNumber("x", currentPositionX);;
	table->PutNumber("y", currentPositionY);;
	table->PutNumber("angle", currentAngle);
}

void Tracker::RotateBy(double deltaAngle) {
	double angle = currentAngle + deltaAngle;
	RotateTo(angle);
}
void Tracker::RotateTo(double angle) {
	Set(currentPositionX, currentPositionY, angle);
}

void Tracker::MoveRF(double right, double forward) {
	double rad = currentAngle * M_PI / 180;
	double dx =  right*cos(rad) + forward*sin(rad);
	double dy = -right*sin(rad) + forward*cos(rad);
	MoveToRel(dx, dy);
}
void Tracker::MoveToRel(double dx, double dy) {
	double x = currentPositionX + dx;
	double y = currentPositionY + dy;
	MoveToAbs(x, y);
}
void Tracker::MoveToAbs(double x, double y) {
	Set(x, y, currentAngle);
}


void Tracker::Set(double x, double y, double angle) {
	UpdatePIDFromTable();
	this->goalPositionX = x;
	this->goalPositionY = y;
	pidrc.SetSetpoint(angle);
	pidrc.Enable();
	pidpc.Enable();
}

void Tracker::MoveToPos(Position* pos) {
	double x = this->currentPositionX;
	double y = this->currentPositionY;
	double angle = this->currentAngle;
	pos->UpdatePositionAbs(&x, &y, &angle);
	Set(x, y, angle);
}

double Tracker::GetPIDRotation() {
	return pidr;
}

double Tracker::GetDistance() {
	GetPosition();
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

void Tracker::PIDDisable() {
	pidpc.Disable();
	pidrc.Disable();
}

void Tracker::UpdatePIDFromTable() {
	double scale = 50;
	double Pdist = DBtable->GetNumber("Slider 0", pidpc.GetP()*scale)/scale;
	double Ddist = DBtable->GetNumber("Slider 1", pidpc.GetD()*scale)/scale;
	double Prot = DBtable->GetNumber("Slider 2", pidrc.GetP()*scale)/scale;
	double Drot = DBtable->GetNumber("Slider 3", pidrc.GetD()*scale)/scale;
	pidpc.SetPID(Pdist, pidpc.GetI(), Ddist);
	pidrc.SetPID(Prot, pidrc.GetI(), Drot);
}

void Tracker::Drive(DriveTrain* drivetrain) {
	const double MAX_POW = 1;
	const double MAX_ROT = 0.75;
	double dx = goalPositionX - currentPositionX;
	double dy = goalPositionY - currentPositionY;
	double goalAngle = atan2(dx, dy) * 180 / M_PI;
	double backward = power;
	if (backward > MAX_POW) backward = MAX_POW;
	if (backward < -MAX_POW) backward = -MAX_POW;
	double rot = pidr;
	if (rot > MAX_ROT) rot = MAX_ROT;
	if (rot < -MAX_ROT) rot = -MAX_ROT;
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
