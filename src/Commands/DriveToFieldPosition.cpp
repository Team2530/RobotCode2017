#include "DriveToFieldPosition.h"
#include "../Robot.h"
DriveToFieldPosition::DriveToFieldPosition(FieldPosition *FP) {
	FieldP = FP;
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
	has_power = false;
}
DriveToFieldPosition::DriveToFieldPosition(FieldPosition *FP, double power) {
	FieldP = FP;
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
	has_power = true;
	max_power = power;
}

// Called just before this Command runs the first time
void DriveToFieldPosition::Initialize() {
	Robot::tracker->PIDReset();
	Robot::tracker->Set(FieldP->GetX(), FieldP->GetY(), FieldP->GetR());
	if (has_power) {
		Robot::tracker->SetMaxPower(max_power);
	} else {
		Robot::tracker->SetMaxPower();
	}
}

// Called repeatedly when this Command is scheduled to run
void DriveToFieldPosition::Execute() {
	Robot::tracker->UpdatePosition();
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
