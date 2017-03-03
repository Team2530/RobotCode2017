#include "MoveBasedOnVision.h"

#include "../Robot.h"

#include "../Positions/RobotRelative.h"

MoveBasedOnVision::MoveBasedOnVision() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::tracker.get());
	Requires(Robot::vision.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void MoveBasedOnVision::Initialize() {
	Robot::vision->Update();
	// Try to compensate for the camera offset to approach with the gear centered
	double camera_offset = 6; // TODO: 6 inches??
	double distance = Robot::vision->GetDistance() - 3*12;
	double displacement = Robot::vision->GetDisplacement() - camera_offset;
	// Move until the takko is (hopefully) centered, about 3 feet away
	Robot::tracker->MoveToPos(new RobotRelative(displacement, distance));
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
