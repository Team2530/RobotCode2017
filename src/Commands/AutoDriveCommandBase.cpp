#include <Commands/AutoDriveCommandBase.h>
#include "../Robot.h"

AutoDriveCommandBase::AutoDriveCommandBase() {
	Requires(Robot::autodrive.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void AutoDriveCommandBase::Initialize() {
	Robot::autodrive->PIDReset();
	this->UpdatePosition();
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveCommandBase::Execute() {
	Robot::tracker->UpdatePosition();
	Robot::autodrive->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveCommandBase::IsFinished() {
	return Robot::autodrive->PIDFinished();
}

// Called once after isFinished returns true
void AutoDriveCommandBase::End() {
	Robot::autodrive->PIDDisable();
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveCommandBase::Interrupted() {
	End();
}
