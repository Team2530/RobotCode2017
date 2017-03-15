#include "MoveBasedOnVision.h"

#include "../Robot.h"

#include "../Positions/RobotRelative.h"
#include "../Positions/AbsoluteAngle.h"

MoveBasedOnVision::MoveBasedOnVision(double distance, double angle) {
	goal = distance;
	lock = angle;
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::tracker.get());
	Requires(Robot::vision.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void MoveBasedOnVision::Initialize() {
	Robot::tracker->PIDReset();
	Robot::vision->Update();
	// Try to compensate for the camera offset to approach with the gear centered
	double camera_offset = -8.5; // the camera is 8.5 from the center of the taco
	double distance = Robot::vision->GetDistance() - goal;
	double displacement = camera_offset - Robot::vision->GetDisplacement();
	std::printf("VISION INIT: Move forward %f in, right %f\n", distance, displacement);
	// Move until the takko is (hopefully) centered, about 3 feet away
	Robot::tracker->MoveToPos(new RobotRelative(-distance, displacement, lock, true));
}

// Called repeatedly when this Command is scheduled to run
void MoveBasedOnVision::Execute() {
	Robot::tracker->GetPosition();
	Robot::tracker->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveBasedOnVision::IsFinished() {
	return Robot::tracker->PIDFinished();
}

// Called once after isFinished returns true
void MoveBasedOnVision::End() {
	std::printf("VISION END\n");
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBasedOnVision::Interrupted() {
	std::printf("VISION INTERRUPT\n");
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();
}
