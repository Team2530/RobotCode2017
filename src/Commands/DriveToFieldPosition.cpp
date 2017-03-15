#include "DriveToFieldPosition.h"
#include "../Robot.h"
DriveToFieldPosition::DriveToFieldPosition(FieldPosition *FP) {
	FieldP = FP;
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void DriveToFieldPosition::Initialize() {
	Robot::tracker->PIDReset();
	Robot::tracker->Set(FieldP->GetX(), FieldP->GetY(), FieldP->GetR());
}

// Called repeatedly when this Command is scheduled to run
void DriveToFieldPosition::Execute() {
	Robot::tracker->GetPosition();
	Robot::tracker->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToFieldPosition::IsFinished() {
	return Robot::tracker->PIDFinished();
}
// Called once after isFinished returns true
void DriveToFieldPosition::End() {
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToFieldPosition::Interrupted() {
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();
}
