#include "DoNothing.h"
#include "Robot.h"

DoNothing::DoNothing(bool oneshot) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());
	once = oneshot;
}

// Called just before this Command runs the first time
void DoNothing::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DoNothing::Execute() {
	Robot::drivetrain->Stop();
}

// Make this return true when this Command no longer needs to run execute()
bool DoNothing::IsFinished() {
	return once;
}

// Called once after isFinished returns true
void DoNothing::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DoNothing::Interrupted() {

}
