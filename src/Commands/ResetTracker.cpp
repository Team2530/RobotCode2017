#include "ResetTracker.h"
#include "../Robot.h"

ResetTracker::ResetTracker() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::autodrive.get());
	Requires(Robot::tracker.get());;
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void ResetTracker::Initialize() {
	Robot::tracker->StartTracking();
}

// Called repeatedly when this Command is scheduled to run
void ResetTracker::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ResetTracker::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ResetTracker::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetTracker::Interrupted() {

}
