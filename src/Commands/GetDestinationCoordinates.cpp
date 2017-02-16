#include "GetDestinationCoordinates.h"
#include "Robot.h"

GetDestinationCoordinates::GetDestinationCoordinates(Objects aTarget, Alliance aTeam) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Alliance team = aTeam;
	Objects target = aTarget;
	Requires(Robot::tracker.get());
}

// Called just before this Command runs the first time
void GetDestinationCoordinates::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void GetDestinationCoordinates::Execute() {
	Robot::tracker->GetTargetCoordinatesX(target, team);
	Robot::tracker->GetTargetCoordinatesY(target);
}

// Make this return true when this Command no longer needs to run execute()
bool GetDestinationCoordinates::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GetDestinationCoordinates::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetDestinationCoordinates::Interrupted() {

}
