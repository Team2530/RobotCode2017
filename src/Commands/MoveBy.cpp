#include "MoveBy.h"
#include "../Robot.h"

MoveBy::MoveBy(double x, double y) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
	goalX = x;
	goalY = y;
}

// Called just before this Command runs the first time
void MoveBy::Initialize() {
	Robot::tracker->PIDReset();
	Robot::tracker->MoveToRel(goalX, goalY);
}

// Called repeatedly when this Command is scheduled to run
void MoveBy::Execute() {
	Robot::tracker->GetPosition();
	Robot::tracker->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveBy::IsFinished() {
	return Robot::tracker->PIDFinished();
}

// Called once after isFinished returns true
void MoveBy::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBy::Interrupted() {
	Robot::drivetrain->Stop();
}
