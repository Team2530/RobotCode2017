#include "../Commands/GetFieldPosition.h"
#include "../RobotMap.h"

#include "../Robot.h"

Tracker::Tracker() :
	Subsystem("TrackerSubsystem"),
	pidrs(&this->currentAngle),
	pidro(&this->pidr),
	pidpo(&this->power),
	pidpc(0.04, 0.000, 0.12, this, &pidpo),
	pidrc(0.02, 0.000, 0.04, &pidrs, &pidro)
{
	frontEncoder = new frc::Encoder(8,9,false, Encoder::CounterBase::k2X );//0,1 gonna change: encoder wires
	sideEncoder = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );//0,1 gonna change ^^
	frontEncoder->SetDistancePerPulse(0.012566/2);//encoderticks/revolution * dpi = 1/1000 * 4pi : ticks/rev = 1/1000 d = 4 pi = 3.14
	sideEncoder->SetDistancePerPulse(-0.012566/2); //^^
	frontLastMeasurement = 0;
	sideLastMeasurement = 0;

	MAX_POW = 0.75;

	pidpc.SetAbsoluteTolerance(2.0); // inches
	pidpc.SetSetpoint(0);
	//pidpc.SetOutputRange(0, 1);

	pidrc.SetInputRange(-180, 180);
	pidrc.SetAbsoluteTolerance(2); // degrees
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
	frontLastMeasurement = 0;
	sideLastMeasurement = 0;
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::StartTracking(double initialX, double initialY, double initialAngle){
	//currentPositionX = Robot::initialX;
	//currentPositionY = 17.25;
	currentPositionX = initialX;
	currentPositionY = initialY;
	currentAngle = initialAngle;
	angleAdjustment = initialAngle;
	if (ahrs == nullptr) {
		ahrs = Robot::oi->GetAHRS();
	}
	if (ahrs != nullptr) {
		ahrs->Reset();
	}
}

void Tracker::UpdatePosition(){
	if (ahrs == nullptr) {
		ahrs = Robot::oi->GetAHRS();
	}
	double side = sideEncoder->GetDistance();
	double front = frontEncoder->GetDistance();
	double distanceX = side - sideLastMeasurement;
	double distanceY = front - frontLastMeasurement;
	sideLastMeasurement = side;
	frontLastMeasurement = front;
	double angle = GetCurrentAngle();
	double rad = angle * M_PI / 180;
	double changeInX = cos(rad) * distanceX + sin(rad) * distanceY;
	double changeInY = cos(rad) * distanceY - sin(rad) * distanceX;
	currentPositionX += changeInX;
	currentPositionY += changeInY;
	currentAngle = angle;
	table->PutNumber("x", currentPositionX);
	table->PutNumber("y", currentPositionY);
	table->PutNumber("dx", goalPositionX - currentPositionX);
	table->PutNumber("dy", goalPositionY - currentPositionY);
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

void Tracker::UpdatePIDFromTable() {
	double scale = 50;
	double Pdist = DBtable->GetNumber("Slider 0", pidpc.GetP()*scale)/scale;
	double Ddist = DBtable->GetNumber("Slider 1", pidpc.GetD()*scale)/scale;
	double Prot = DBtable->GetNumber("Slider 2", pidrc.GetP()*scale)/scale;
	double Drot = DBtable->GetNumber("Slider 3", pidrc.GetD()*scale)/scale;
	pidpc.SetPID(Pdist, pidpc.GetI(), Ddist);
	pidrc.SetPID(Prot, pidrc.GetI(), Drot);
}

void Tracker::Set(double x, double y, double angle) {
	//UpdatePIDFromTable();
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
	UpdatePosition();
	double dx = this->goalPositionX - this->currentPositionX;
	double dy = this->goalPositionY - this->currentPositionY;
	double distance = hypot(dx,dy);
	//std::printf("Distance: %f\n", distance);
	return distance;
}
double Tracker::PIDGet() {
	return GetDistance();
}

bool Tracker::PIDFinished() {
	bool correctPosition = pidpc.OnTarget();
	bool correctHeading = pidrc.OnTarget();
	if (correctPosition && !correctHeading) {
		double goal = pidrc.GetSetpoint();
		double deviation = goal - currentAngle;
		std::printf("Waiting to rotate (%f deg away)\n", deviation);
		//if (fabs(deviation) < 1) return true;
	} else if (correctHeading && !correctPosition) {
		double dx = this->goalPositionX - this->currentPositionX;
		double dy = this->goalPositionY - this->currentPositionY;
		double distance = hypot(dx,dy);
		std::printf("Waiting to move (%f in away)\n", distance);
		//if (distance < 0.1) return true;
	}
	return correctPosition && correctHeading;
}

void Tracker::PIDReset() {
	pidpc.Reset();
	pidrc.Reset();
}

void Tracker::PIDDisable() {
	pidpc.Disable();
	pidrc.Disable();
}

const double MAX_ROT = 0.5;

void Tracker::SetMaxPower(double pow) {
	MAX_POW = pow;
}

void Tracker::Drive(DriveTrain* drivetrain) {
	double dx = goalPositionX - currentPositionX;
	double dy = goalPositionY - currentPositionY;
	double goalAngle = atan2(dx, dy) * 180 / M_PI;
	double pwr = power;
	if (pwr > MAX_POW) pwr = MAX_POW;
	if (pwr < -MAX_POW) pwr = -MAX_POW;
	double rot = pidr;
	if (rot > MAX_ROT) rot = MAX_ROT;
	if (rot < -MAX_ROT) rot = -MAX_ROT;
	//std::printf("Drive command: %f\n", backward);

	// Rotate coordinates to robot oriented
	double rad = (goalAngle - currentAngle + 90) * M_PI/180;
	double x = pwr*cos(rad);
	double y = pwr*sin(rad);

	drivetrain->DirectDrive(
		x, y, rot
	);
}

void Tracker::EnableHeadingLock(bool enabled) {
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
		UpdatePosition();
		pidr = 0; // reset PID output to 0, just in case
		pidrc.Reset();
		pidrc.SetSetpoint(currentAngle);
		//std::printf("Lock to heading %f\n", currentAngle);
		pidrc.Enable();
		headingLockEnabled = true;
		return;
	}
}

double Tracker::GetCurrentPositionX(){
	return currentPositionX;
}
double Tracker::GetCurrentPositionY(){
	return currentPositionY;
}
double Tracker::GetCurrentAngle(){
	double angle =  ahrs != nullptr ? ahrs->GetYaw()+angleAdjustment : 0.0;
	while (angle > 180) angle -= 360;
	while (angle < -180) angle += 360;
	return angle;
}
