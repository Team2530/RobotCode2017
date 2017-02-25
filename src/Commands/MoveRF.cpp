#include "MoveRF.h"
#include "../Robot.h"

MoveRF::MoveRF(double right, double forward) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
	r = right;
	f = forward;
}

// Called just before this Command runs the first time
void MoveRF::Initialize() {
	Robot::tracker->PIDReset();
	Robot::tracker->MoveRF(r, f);
}

// Called repeatedly when this Command is scheduled to run
void MoveRF::Execute() {
	Robot::tracker->GetPosition();
	Robot::tracker->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveRF::IsFinished() {
	return Robot::tracker->PIDFinished();
}

// Called once after isFinished returns true
void MoveRF::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveRF::Interrupted() {
	Robot::drivetrain->Stop();
}
