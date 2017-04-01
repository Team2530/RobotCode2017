#include "../Commands/GetFieldPosition.h"
#include "../RobotMap.h"

#include "../Robot.h"

Tracker::Tracker() :
	Subsystem("TrackerSubsystem"),
	ahrs(nullptr), // obtained from OI later
	frontLastMeasurement(0),
	sideLastMeasurement(0),
	currentPositionX(0),
	currentPositionY(0),
	currentAngle(0),
	angleAdjustment(0)
{
	frontEncoder = new frc::Encoder(8,9,false, Encoder::CounterBase::k2X );//0,1 gonna change: encoder wires
	sideEncoder = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );//0,1 gonna change ^^
	frontEncoder->SetDistancePerPulse(0.012566/2);//encoderticks/revolution * dpi = 1/1000 * 4pi : ticks/rev = 1/1000 d = 4 pi = 3.14
	sideEncoder->SetDistancePerPulse(-0.012566/2); //^^

	table = NetworkTable::GetTable("robotPosition");
}
void Tracker::InitDefaultCommand() {
	frontEncoder->Reset();
	sideEncoder->Reset();
	frontLastMeasurement = 0;
	sideLastMeasurement = 0;
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::StartTracking(double initialX, double initialY, double initialAngle){
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
	table->PutNumber("angle", currentAngle);
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
