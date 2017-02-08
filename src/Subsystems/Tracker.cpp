#include "../Commands/GetFieldPosition.h"
#include "Tracker.h"
#include "../RobotMap.h"
#include "AHRS.h"
#include "Robot.h"

Tracker::Tracker() : Subsystem("TrackerSubsystem") {
	//ahrs= new AHRS(SerialPort::kMXP);
	xAccel = new float(AHRS->GetRawAccelX());
	yAccel = new float(AHRS->GetRawAccelY());
	angle = new double(AHRS->GetAngle());
	xDistance = new double(sideEncoder.Get());
	yDistance = new double(frontEncoder.Get());
	//feel like making this to complicated: finish implimenting encoders!
}

void Tracker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::GetPosition(){
	double xValue;//can be set depending where are on map
	double yValue;//^^
	//angle = angle.Get();
	//xAccel = xAccel.Get();
	//yAccel = yAccel.Get();
	double distanceX;
	double distanceY;
	//xValue += (distanceX)(angle) + (distanceY)(angle);
	//yValue += (distanceY)(angle) - (distanceX)(angle);

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
