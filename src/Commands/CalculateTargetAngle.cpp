#include "CalculateTargetAngle.h"

CalculateTargetAngle::CalculateTargetAngle(double *x, double *y, double *angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

xpointer = x;
ypointer = y;
anglepointer = angle;

}

// Called just before this Command runs the first time
void CalculateTargetAngle::Initialize() {

	double currentPositionX = Robot::tracker->GetcurrentPositionX();
	double currentPositionY = Robot::tracker->GetcurrentPositionY();

	double TargetAngle = 0; //get real angle

	double deltaxValue = *xpointer - currentPositionX;
	double deltayValue = *ypointer - currentPositionY;

	if (deltaxValue < 0 && deltayValue > 0){
			TargetAngle = atan ((-deltaxValue) / deltayValue) + 90;
		}
	if (deltaxValue > 0 && deltayValue > 0){
			TargetAngle = atan (deltayValue / deltaxValue);
		}
	if (deltaxValue > 0 && deltayValue < 0){
			TargetAngle = -atan ((-deltayValue) / deltaxValue);
	if (deltaxValue < 0 && deltayValue < 0){
			TargetAngle = -(atan ((-deltaxValue) / (-deltayValue)) + 90);
		}

*anglepointer = TargetAngle;

}

// Called repeatedly when this Command is scheduled to run
void CalculateTargetAngle::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool CalculateTargetAngle::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void CalculateTargetAngle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CalculateTargetAngle::Interrupted() {

}
