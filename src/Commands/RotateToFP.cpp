#include "RotateToFP.h"

RotateToFP::RotateToFP() {
	FieldP = FP;
		Requires(Robot::tracker.get());
		Requires(Robot::drivetrain.get());
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void RotateToFP::Initialize() {
	Robot::tracker->PIDReset();
	Robot::tracker->Set(Robot::tracker->GetCurrentPositionX(),
			            Robot::tracker-> GetCurrentPositionY(),
			            Robot::tracker->GetCurrentPositionR());
}

// Called repeatedly when this Command is scheduled to run
void RotateToFP::Execute() {
	Robot::tracker->GetPosition();
	Robot::tracker->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool RotateToFP::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RotateToFP::End() {
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateToFP::Interrupted() {

}
