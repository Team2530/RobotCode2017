#include "MoveBasedOnVision.h"

#include "../Robot.h"

#include "../Positions/RobotRelative.h"
#include "../Positions/AbsoluteAngle.h"

MoveBasedOnVision::MoveBasedOnVision(double distance, FieldPosition* fieldposition) {
	goal = distance;
	fp = fieldposition;
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::tracker.get());
	Requires(Robot::vision.get());
	Requires(Robot::led.get());
	Requires(Robot::drivetrain.get());
	Requires(Robot::cameraservo.get());
}

// Called just before this Command runs the first time
void MoveBasedOnVision::Initialize() {
	Robot::cameraservo->AimTaco();
	Robot::led->Set(true);
	Robot::autodrive->PIDReset();
	Robot::vision->Update();
	double lock;
	if (fp != nullptr) {
		lock = fp->GetR();
	} else {
		lock = Robot::tracker->GetCurrentAngle();
		// If we are within 10 degrees of a gear position, lock onto that.
		for (double angle = 90-60; angle <= 90+60; angle += 60) {
			if (lock < angle+25 && lock > angle-25) {
				std::printf("Lock on to %f (current: %f)\n", angle, lock);
				lock = angle;
				break;
			}
		}
	}
	double distance = 0;
	double displacement = 10;
	if (Robot::vision->GetValid()) {
		// Try to compensate for the camera offset to approach with the gear centered
		double camera_offset = -8.5; // the camera is 8.5 from the center of the taco
		distance = Robot::vision->GetDistance() - goal;
		displacement = camera_offset - Robot::vision->GetDisplacement();
		std::printf("VISION INIT: Move forward %f in, right %f\n", distance, displacement);
		// Move until the takko is (hopefully) centered, about 3 feet away
	} else {
		std::printf("VISION FAILED: move in %fin\n", distance);
	}
	Robot::autodrive->MoveToPos(new RobotRelative(-distance, displacement, lock, true));
}

// Called repeatedly when this Command is scheduled to run
void MoveBasedOnVision::Execute() {
	Robot::tracker->GetPosition();
	Robot::autodrive->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool MoveBasedOnVision::IsFinished() {
	return Robot::autodrive->PIDFinished();
}

// Called once after isFinished returns true
void MoveBasedOnVision::End() {
	std::printf("VISION END\n");
	Robot::autodrive->PIDDisable();
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBasedOnVision::Interrupted() {
	std::printf("VISION INTERRUPT\n");
	Robot::autodrive->PIDDisable();
	Robot::drivetrain->Stop();
}
