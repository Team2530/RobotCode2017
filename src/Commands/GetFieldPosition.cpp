#include <Commands/GetFieldPosition.h>
#include "Robot.h"

GetFieldPosition::GetFieldPosition() : Command("GetFieldPosition"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::tracker.get());
}

// Called just before this Command runs the first time
void GetFieldPosition::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GetFieldPosition::Execute() {
	Robot::tracker->GetPosition();
}

// Make this return true when this Command no longer needs to run execute()
bool GetFieldPosition::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GetFieldPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetFieldPosition::Interrupted() {
	End();
}
