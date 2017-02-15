#include "DeliverMiddleGear.h"
#include "Robot.h"

DeliverMiddleGear::DeliverMiddleGear() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
	Requires(Robot::tracker.get());
}

// Called just before this Command runs the first time
void DeliverMiddleGear::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DeliverMiddleGear::Execute() {
	Robot::tracker->GetGearPositionX(MIDDLE_GEAR_DELIVERY);
	Robot::tracker->GetGearPositionY(MIDDLE_GEAR_DELIVERY);
}

// Make this return true when this Command no longer needs to run execute()
bool DeliverMiddleGear::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DeliverMiddleGear::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DeliverMiddleGear::Interrupted() {

}
