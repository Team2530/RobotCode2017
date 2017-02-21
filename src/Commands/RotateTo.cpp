#include "RotateTo.h"
#include "../Robot.h"

RotateTo::RotateTo(double angle) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
	goal = angle;
}

// Called just before this Command runs the first time
void RotateTo::Initialize() {
	Robot::tracker->PIDReset();
	Robot::tracker->RotateTo(goal);
}

// Called repeatedly when this Command is scheduled to run
void RotateTo::Execute() {
	Robot::tracker->GetPosition();
	Robot::tracker->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool RotateTo::IsFinished() {
	return Robot::tracker->PIDFinished();
}

// Called once after isFinished returns true
void RotateTo::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateTo::Interrupted() {
	Robot::drivetrain->Stop();
}
