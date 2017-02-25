#include "DriveForward.h"

#include "Robot.h"
DriveForward::DriveForward():Command("DriveForward") {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());;
}
DriveForward::DriveForward(double x, double y) {
	double currentPositionx = Robot::tracker->GetCurrentPositionX();
	double currentPositiony = Robot::tracker->GetCurrentPositionY();

	double deltaxValue = x - currentPositionx;
	double deltayValue = y - currentPositiony;
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {
	Robot::drivetrain->DriveForward();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveForward::End() {
	Robot::drivetrain->Stop();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {
	Robot::drivetrain->Stop();
}
