//this used to be called output, if anything is calling the file 'Output' change it to 'Dump'
#include <Commands/Dump.h>
#include "Robot.h"

Dump::Dump(): Command("Dump") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::dumper.get());
}

// Called just before this Command runs the first time
void Dump::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Dump::Execute() {
	if (!IsFinished())
		Robot::dumper->Dump();
}

// Make this return true when this Command no longer needs to run execute()
bool Dump::IsFinished() {
	//return Robot::dumper->FinishedDumping();
	return Robot::dumper->isDumperAtTop();
}

// Called once after isFinished returns true
void Dump::End() {
	Robot::dumper->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Dump::Interrupted() {
	End();
}
