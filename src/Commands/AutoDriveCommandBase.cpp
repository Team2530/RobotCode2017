#include <Commands/AutoDriveCommandBase.h>
#include "../Robot.h"

AutoDriveCommandBase::AutoDriveCommandBase() {
	Requires(Robot::autodrive.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
// Set the position based on the derived class.
void AutoDriveCommandBase::Initialize() {
	Robot::tracker->UpdatePosition();
	// Reset the max power to default (just in case)
	Robot::autodrive->SetMaxPower();
	this->UpdatePosition(); // needs to be implemented in derived class
}

// Called repeatedly when this Command is scheduled to run
// Ensure our tracker has the correct position
void AutoDriveCommandBase::Execute() {
	Robot::tracker->UpdatePosition();
	Robot::autodrive->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
// Wait for the PIDs to finish
bool AutoDriveCommandBase::IsFinished() {
	return Robot::autodrive->PIDFinished();
}

// Called once after isFinished returns true
// Disable the PID loop and stop the drive train
void AutoDriveCommandBase::End() {
	Robot::autodrive->PIDDisable();
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
// See AutoDriveCommandBase::End()
void AutoDriveCommandBase::Interrupted() {
	End();
}
