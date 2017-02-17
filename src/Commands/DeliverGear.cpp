#include "DeliverGear.h"
#include "Robot.h"

DeliverGear::DeliverGear() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
	Requires(Robot::tracker.get());
}

// Called just before this Command runs the first time
void DeliverGear::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DeliverGear::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DeliverGear::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DeliverGear::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DeliverGear::Interrupted() {

}
