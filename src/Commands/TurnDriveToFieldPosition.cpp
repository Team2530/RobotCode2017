//this command turns in the direction of the field position and then drives to that field position
#include "TurnDriveToFieldPosition.h"
#include "../Robot.h"
#include "Subsystems/Tracker.h"
#include "FieldPositions/FieldPosition.h"

TurnDriveToFieldPosition::TurnDriveToFieldPosition(FieldPosition *FP) {
	FieldP = FP;
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void TurnDriveToFieldPosition::Initialize() {

	double dx = goalPositionX - currentPositionX;
	double dy = goalPositionY - currentPositionY;
	double goalAngle = atan2(dx, dy) * 180 / M_PI;
	Robot::tracker->PIDReset();
	Robot::tracker->Set(FieldP->GetX(), FieldP->GetY(),goalAngle);
}

// Called repeatedly when this Command is scheduled to run
void TurnDriveToFieldPosition::Execute() {
	Robot::tracker->GetPosition();
	Robot::tracker->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool TurnDriveToFieldPosition::IsFinished() {
	return Robot::tracker->PIDFinished();
}
// Called once after isFinished returns true
void TurnDriveToFieldPosition::End() {
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnDriveToFieldPosition::Interrupted() {
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();
}
