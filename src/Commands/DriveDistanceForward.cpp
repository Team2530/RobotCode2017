#include "DriveDistanceForward.h"

#include "Robot.h"

DriveDistanceForward::DriveDistanceForward(double *distanceToTravel) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
	driveDistanceForward=distanceToTravel;
}

// Called just before this Command runs the first time
void DriveDistanceForward::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveDistanceForward::Execute() {
	Robot::drivetrain->DriveDistanceForward();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistanceForward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveDistanceForward::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistanceForward::Interrupted() {

}
