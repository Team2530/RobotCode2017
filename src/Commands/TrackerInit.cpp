#include "TrackerInit.h"
#include "../Robot.h"

TrackerInit::TrackerInit(StartPosition position, Alliance team) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	this->position = position;
	this->team = team;
}

// Called just before this Command runs the first time
void TrackerInit::Initialize() {
	Robot::tracker->StartTracking(this->position, this->team);
	Robot::tracker->GetHopperPositionX(this->team);
	Robot::tracker->GetBoilerPositionX(this->team);

}

// Called repeatedly when this Command is scheduled to run
void TrackerInit::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TrackerInit::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TrackerInit::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TrackerInit::Interrupted() {

}
