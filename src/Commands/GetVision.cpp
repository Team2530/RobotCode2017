#include "GetVision.h"
#include "../Robot.h"
#include "../Positions/RobotRelative.h"
#include "../Positions/AbsoluteAngle.h"

GetVision::GetVision(FieldPosition* fieldposition) {
	fp = fieldposition;
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::vision.get());
	Requires(Robot::led.get());
	Requires(Robot::drivetrain.get());
	Requires(Robot::cameraservo.get());
	Requires(Robot::autodrive.get());
}

void GetVision::UpdatePosition() {
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
	double distance = -25;
	double displacement = 0;
	if (Robot::vision->GetValid() && Robot::vision->GetTargets() == 2) {
		distance = 0;
		std::printf("VISION already ok\n");
	} else {
		std::printf("VISION not captured: move out\n");
	}
	if (orientation == FRONT_FORWARD) {
		Robot::autodrive->MoveToPos(new RobotRelative(displacement, distance, lock, true));
	} else {
		Robot::autodrive->MoveToPos(new RobotRelative(-distance, displacement, lock, true));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GetVision::IsFinished() {
	bool donemoving = AutoDriveCommandBase::IsFinished();
	if (donemoving) return true;
	Robot::vision->Update();
	if (Robot::vision->GetValid() && Robot::vision->GetTargets() == 2) {
		return true;
	}
	return false;
}
