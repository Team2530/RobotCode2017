#include "MoveBasedOnVision.h"

#include "../Robot.h"

MoveBasedOnVision::MoveBasedOnVision() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::tracker.get());
	Requires(Robot::vision.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void MoveBasedOnVision::Initialize() {
	Robot::vision->Update();
	double distance = Robot::vision->GetDistance() - 3*12;
	double displacement = Robot::vision->GetDisplacement();
	// Move until the camera is (hopefully) centered, about 3 feet away
	Robot::tracker->MoveToRel(distance, displacement);
}

// Called repeatedly when this Command is scheduled to run
void MoveBasedOnVision::Execute() {
	Robot::tracker->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveBasedOnVision::IsFinished() {
	return Robot::tracker->PIDFinished();
}

// Called once after isFinished returns true
void MoveBasedOnVision::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBasedOnVision::Interrupted() {

}
