#include "DriveToPosition.h"

#include "../Robot.h"

DriveToPosition::DriveToPosition(Position* p) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
	pos = p;
}

// Called just before this Command runs the first time
void DriveToPosition::Initialize() {
	Robot::tracker->PIDReset();
	Robot::tracker->MoveToPos(pos);
}

// Called repeatedly when this Command is scheduled to run
void DriveToPosition::Execute() {
	Robot::tracker->GetPosition();
	Robot::tracker->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToPosition::IsFinished() {
	return Robot::tracker->PIDFinished();
}

// Called once after isFinished returns true
void DriveToPosition::End() {
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToPosition::Interrupted() {
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();
}
