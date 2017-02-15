#include "PullVisionEstimate.h"

#include "../Robot.h"

PullVisionEstimate::PullVisionEstimate() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::vision.get());
}

// Called just before this Command runs the first time
void PullVisionEstimate::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PullVisionEstimate::Execute() {
	Robot::vision->Update();
}

// Make this return true when this Command no longer needs to run execute()
bool PullVisionEstimate::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PullVisionEstimate::End() {
	//Robot::vision->Cancel();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PullVisionEstimate::Interrupted() {
	//Robot::vision->Cancel();
}
