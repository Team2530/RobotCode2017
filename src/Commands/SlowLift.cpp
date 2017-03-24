#include "SlowLift.h"

SlowLift::SlowLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::lifter.get());
}

// Called just before this Command runs the first time
void SlowLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SlowLift::Execute() {
	Robot::lifter->Slow();

}

// Make this return true when this Command no longer needs to run execute()
bool SlowLift::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SlowLift::End() {
	Robot::lifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SlowLift::Interrupted() {
	Robot::lifter->Stop();

}
