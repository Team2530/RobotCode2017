#include "Lift.h"

Lift::Lift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::lifter.get());
}

// Called just before this Command runs the first time
void Lift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Lift::Execute() {
	Robot::lifter->Go();

}

// Make this return true when this Command no longer needs to run execute()
bool Lift::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Lift::End() {
	Robot::lifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Lift::Interrupted() {
	Robot::lifter->Stop();

}
