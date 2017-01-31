#include <Commands/GetFieldPosition.h>
#include "AHRS.h"

GetFeildPosition::GetFeildPosition() : Command("GetFeildPosition"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::tracker.Get())
}

// Called just before this Command runs the first time
void GetFeildPosition::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GetFeildPosition::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool GetFeildPosition::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GetFeildPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetFeildPosition::Interrupted() {

}
