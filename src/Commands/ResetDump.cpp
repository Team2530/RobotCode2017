#include "ResetDump.h"
#include <Commands/Dump.h>
#include "Robot.h"

ResetDump::ResetDump() {
	Requires(Robot::dumper.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ResetDump::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ResetDump::Execute() {
	Robot::dumper->ResetDump();
}

// Make this return true when this Command no longer needs to run execute()
bool ResetDump::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ResetDump::End() {
	Robot::dumper->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetDump::Interrupted() {

}
