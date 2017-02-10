#include <Commands/Output.h>
#include "Robot.h"

Output::Output(): Command("Output") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::dumper.get());
}

// Called just before this Command runs the first time
void Output::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Output::Execute() {
	Robot::dumper->Dump();
}

// Make this return true when this Command no longer needs to run execute()
bool Output::IsFinished() {
	//return Robot::dumper->FinishedDumping();// no finished dumping
	return true;
}

// Called once after isFinished returns true
void Output::End() {
	Robot::dumper->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Output::Interrupted() {
	End();
}
