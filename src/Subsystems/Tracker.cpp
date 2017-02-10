#include "../Commands/GetFieldPosition.h"
#include "Tracker.h"
#include "../RobotMap.h"


#include "Robot.h"
#include "math.h"

Tracker::Tracker() : Subsystem("TrackerSubsystem") {


frontEncoder = new Encoder(0,1,false, Encoder::CounterBase::k2X );//0,1 gonna change: encoder wires
sideEncoder = new Encoder(0,1,false, Encoder::CounterBase::k2X );//0,1 gonna change ^^
frontEncoder->SetDistancePerPulse(0.012566);//encoderticks/revolution * dpi = 1/1000 * 4pi : ticks/rev = 1/1000 d = 4 pi = 3.14
sideEncoder->SetDistancePerPulse(0.012566); //^^
ahrs= new AHRS(SerialPort::kMXP);//check port
}
void Tracker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	frontEncoder->Reset();
	sideEncoder->Reset();
	ahrs->Reset();
	SetDefaultCommand(new GetFieldPosition());
}

void Tracker::GetPosition(){

	double distanceX = sideEncoder->GetDistance();
	double distanceY = frontEncoder->GetDistance();
	double angle = ahrs->GetAngle();
	double changeInX = cos(angle)* distanceX + sin(angle) * distanceY;
	double changeInY = cos(angle)*distanceY - sin(angle) * distanceX;
	xValue += changeInX ;
	yValue += changeInY ;
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
