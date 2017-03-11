#include "ReverseLift.h"

ReverseLift::ReverseLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::lifter.get());
}

// Called just before this Command runs the first time
void ReverseLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ReverseLift::Execute() {
	Robot::lifter->Reverse();
}

// Make this return true when this Command no longer needs to run execute()
bool ReverseLift::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ReverseLift::End() {
	Robot::lifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseLift::Interrupted() {
	Robot::lifter->Stop();
}
