#include "CalculatePositionFromDistance.h"
#include "math.h"
#include "../RobotMap.h"
#include "Robot.h"

/*
 *What this needs to do:
 *get current position and angle
 *distance is a parameter
 *trying to get new coordinates of spot the robot is supposed to get to
 *pointers for x and y will be parameters
 */
CalculatePositionFromDistance::CalculatePositionFromDistance(double *angle, double *distanceForwardToGo, double *currentPositionX, double *currentPositionY) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
		angleCPFD = angle;
		distanceForwardToGoCPFD = distanceForwardToGo;
		currentPositionXCPFD = currentPositionX; // Right
		currentPositionYCPFD = currentPositionY; // Forward
		Requires(Robot::tracker.get());
}

// Called just before this Command runs the first time
void CalculatePositionFromDistance::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CalculatePositionFromDistance::Execute() {
	//CPFDCoordinatesX = Robot::tracker->currentPositionX.get + (distanceForwardToGo * cos(Robot::tracker->angle.get * M_PI / 180));
	//CPFDCoordinatesY = Robot::tracker->currentPositionY.get + (distanceForwardToGo * sin(Robot::tracker->angle.get * M_PI / 180));
}

// Make this return true when this Command no longer needs to run execute()
bool CalculatePositionFromDistance::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void CalculatePositionFromDistance::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CalculatePositionFromDistance::Interrupted() {

}
