#include "../Commands/GetFieldPosition.h"
#include "Tracker.h"
#include "../RobotMap.h"


#include "Robot.h"
#include "math.h"

Tracker::Tracker() :
	Subsystem("TrackerSubsystem"),
	pidxs(&this->currentPositionX),
	pidys(&this->currentPositionY),
	pidrs(&this->currentAngle),
	pidxo(&this->pidx),
	pidyo(&this->pidy),
	pidro(&this->pidr),
	pidxc(0.1, 0.001, 0.0, &pidxs, &pidxo),
	pidyc(0.1, 0.001, 0.0, &pidys, &pidyo),
	pidrc(0.1, 0.001, 0.0, &pidrs, &pidro)
{
	frontEncoder = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );//0,1 gonna change: encoder wires
	sideEncoder = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );//0,1 gonna change ^^
	frontEncoder->SetDistancePerPulse(0.012566);//encoderticks/revolution * dpi = 1/1000 * 4pi : ticks/rev = 1/1000 d = 4 pi = 3.14
	sideEncoder->SetDistancePerPulse(0.012566); //^^
	ahrs = new AHRS(SerialPort::kMXP);//check port
}
void Tracker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	frontEncoder->Reset();
	sideEncoder->Reset();
	ahrs->Reset();
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::StartTracking(StartPosition position, StartTeam team){
	currentPositionX = Robot::tracker->GetOriginalPositionX(position, team);
	currentPositionY = 35.50;
	currentAngle = 0;
}

void Tracker::GetPosition(){
	double distanceX = sideEncoder->GetDistance();
	double distanceY = frontEncoder->GetDistance();
	double angle =  ahrs->GetAngle();
	double rad = angle * M_PI / 180;
	double changeInX = cos(rad)*distanceX + sin(rad) * distanceY;
	double changeInY = cos(rad)*distanceY - sin(rad) * distanceX;
	currentPositionX += changeInX;
	currentPositionY += changeInY;
	currentAngle = angle;
	frontEncoder->Reset();
	sideEncoder->Reset();
}
double Tracker::GetOriginalPositionX(StartPosition position, StartTeam team){
	double xValue;
	if (team == RED_TEAM){
		if (position == START_LEFT){
			xValue = 75.545; //all these are starting coordinates in inches
		}
		else if (position == START_MIDDLE){
			xValue = 183.107;
		}
		else{ // START_RIGHT
			xValue = 249.587;
		}
	}
	else{ //BLUE_TEAM
		if (position == START_LEFT){
			xValue = 73.712;
		}
		else if (position == START_MIDDLE){
			xValue = 140.192;
		}
		else{//START_RIGHT
			xValue = 235.584;
		}
	}
	return xValue;

}
double Tracker::GetForwardDistance(){
	return frontEncoder->GetDistance();
}
double Tracker::GetSideDistance(){
	return sideEncoder->GetDistance();
}

void Tracker::RotateTo(double angle) {
	pidrc.SetSetpoint(angle);
}

void Tracker::RotateBy(double deltaAngle) {
	double angle = currentAngle + deltaAngle;
	RotateTo(angle);
}

void Tracker::MoveToRel(double forward, double right) {
}

void Tracker::MoveToAbs(double x, double y) {
}

double Tracker::GetPIDX() {
	return pidx;
}

double Tracker::GetPIDY() {
	return pidy;
}

double Tracker::GetPIDRotation() {
	return pidr;
}

double Tracker::GetPIDBackward() {

}

double Tracker::GetPIDRight() {
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
