#include "MoveBasedOnVision.h"

#include "../Robot.h"

#include "../Positions/RobotRelative.h"
#include "../Positions/AbsoluteAngle.h"

MoveBasedOnVision::MoveBasedOnVision(double distance, FieldPosition* fieldposition) {
	goal = distance;
	fp = fieldposition;
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::vision.get());
	Requires(Robot::led.get());
	Requires(Robot::drivetrain.get());
	Requires(Robot::cameraservo.get());
	Requires(Robot::autodrive.get());
}

// Called just before this Command runs the first time
void MoveBasedOnVision::UpdatePosition() {
	Robot::led->Set(true);
	Robot::vision->Update();
	double lock;
	double orientation = Robot::cameraservo->facing; // TAKKO_FOWARD or FRONT_FORWARD
	if (fp != nullptr) {
		lock = fp->GetR();
	} else {
		lock = Robot::tracker->GetCurrentAngle();
		// If we are within 10 degrees of a gear position, lock onto that.
		for (double angle = orientation-60; angle <= orientation+60; angle += 60) {
			if (lock < angle+25 && lock > angle-25) {
				std::printf("Lock on to %f (current: %f)\n", angle, lock);
				lock = angle;
				break;
			}
		}
	}
	double distance = -20;
	double displacement = 0;
	if (Robot::vision->GetValid()) {
		// Try to compensate for the camera offset to approach with the gear centered
		// TODO: CHANGE BASED ON MIRACLE MAX
		double camera_offset;
		if (orientation == FRONT_FORWARD) {
			camera_offset = -13.75;
		} else { // orientation == TAKKO_FORWARD
			camera_offset = 8.5;
		}
		distance = Robot::vision->GetDistance() - goal;
		displacement = camera_offset - Robot::vision->GetDisplacement();
		std::printf("VISION INIT: Move forward %f in, right %f\n", distance, displacement);
		// Move until the takko is (hopefully) centered, about 3 feet away
	} else {
		std::printf("VISION FAILED: move in %fin, right%fin\n", distance, displacement);
		Robot::drivetrain->Stop();
	}
	if (orientation == FRONT_FORWARD) {
		Robot::autodrive->MoveToPos(new RobotRelative(displacement, distance, lock, true));
	} else {
		Robot::autodrive->MoveToPos(new RobotRelative(-distance, displacement, lock, true));
	}
}

// Called once after isFinished returns true
void MoveBasedOnVision::End() {
	std::printf("VISION END\n");
	AutoDriveCommandBase::End();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveBasedOnVision::Interrupted() {
	std::printf("VISION INTERRUPT\n");
	AutoDriveCommandBase::Interrupted();
}
