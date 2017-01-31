#include "../Commands/GetFieldPosition.h"
#include "Tracker.h"
#include "../RobotMap.h"
#include "AHRS.h"

Tracker::Tracker() : Subsystem("TrackerSubsystem") {

}

void Tracker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::GetPosition(){
	double xValue;
	double yValue;
	Tracker->UpdateDisplacement(float GetRawAccelX, float GetRawAccelY, int 50, bool true)
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
