#include "DriveToPosition.h"

#include "../Robot.h"

#include "../Subsystems/Tracker.h"

DriveToPosition::DriveToPosition(double *x, double *y) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
	xposition = x;
	yposition = y;
}

// Called just before this Command runs the first time
void DriveToPosition::Initialize() {
	Robot::tracker->PIDReset();
	Robot::tracker->MoveToAbs(*xposition, *yposition);
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
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToPosition::Interrupted() {
	Robot::drivetrain->Stop();
}
