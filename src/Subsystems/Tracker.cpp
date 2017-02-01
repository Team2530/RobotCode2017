#include "../Commands/GetFieldPosition.h"
#include "Tracker.h"
#include "../RobotMap.h"
#include "AHRS.h"
#include "DriveTrain.h"
#include "Robot.h"

Tracker::Tracker() : Subsystem("TrackerSubsystem") {

void Tracker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::GetPosition(){
	double xValue;//can be set depending where are on map
	double yValue;//^^

	double distanceX = sideEncoder->GetDistance();
	double distanceY = frontEncoder->GetDistance();
	double angle = ahrs->GetAngle();
}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
