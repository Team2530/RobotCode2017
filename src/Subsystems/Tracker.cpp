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
	angleAdjustment(0)
{
	frontEncoder = new frc::Encoder(8,9,false, Encoder::CounterBase::k2X );//0,1 gonna change: encoder wires
	sideEncoder = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );//0,1 gonna change ^^
	frontEncoder->SetDistancePerPulse(0.012566/2);//encoderticks/revolution * dpi = 1/1000 * 4pi : ticks/rev = 1/1000 d = 4 pi = 3.14
	sideEncoder->SetDistancePerPulse(-0.012566/2); //^^

	table = NetworkTable::GetTable("robotPosition");
	ahrs = new AHRS(SPI::Port::kMXP);
	ahrs->Reset();
}

// Set a command to update this tracker with the current position every iteration
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
	angleAdjustment = initialAngle;
	if (ahrs != nullptr) {
		ahrs->Reset();
	}
}

void Tracker::UpdatePosition(){
	double side = sideEncoder->GetDistance();
	double front = frontEncoder->GetDistance();
	double distanceX = side - sideLastMeasurement;
	double distanceY = front - frontLastMeasurement;
	previousPositionX=currentPositionX;
	previousPositionY=currentPositionY;
	previousAngle=currentAngle;
	currentAngle=GetCurrentAngle();
	// Only do our calculations if at least one encoder's value has changed
	if (distanceX != 0 || distanceY != 0) {
		sideLastMeasurement = side;
		frontLastMeasurement = front;
		double rad = currentAngle * M_PI / 180;
		double changeInX = cos(rad) * distanceX + sin(rad) * distanceY;
		double changeInY = cos(rad) * distanceY - sin(rad) * distanceX;
		currentPositionX += changeInX;
		currentPositionY += changeInY;
	}
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
	double angle =  ahrs != nullptr ? ahrs->GetYaw()+angleAdjustment : 0.01;
	// Rotate the output around by a full resolution if it is outside of +/-180
	// (This will only occur if angleAdjustment is nonzero, as GetYaw is always in that range)
	while (angle > 180) angle -= 360;
	while (angle < -180) angle += 360;
	return angle;
}

bool Tracker::IsRobotStopped() {
	bool isXStopped = std::fabs(currentPositionX - previousPositionX) < 0.01;
	bool isYStopped = std::fabs(currentPositionY - previousPositionY) < 0.01;
	bool isAngleStopped = std::fabs(GetCurrentAngle() - previousAngle) < 0.1;

	if (isXStopped && isYStopped && isAngleStopped) {
		table->PutNumber("stopped", 1);
		return true;
	}
	else {
		table->PutNumber("stopped", 0);
		return false;
	}
}
