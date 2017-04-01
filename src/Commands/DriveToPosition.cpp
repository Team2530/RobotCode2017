#include "DriveToPosition.h"

#include "../Robot.h"

DriveToPosition::DriveToPosition(Position* p) {
	pos = p;
	has_power = false;
}

DriveToPosition::DriveToPosition(Position* p, double speed) {
	pos = p;
	has_power = true;
	max_power = speed;
}

// Called just before this Command runs the first time
void DriveToPosition::UpdatePosition() {
	Robot::autodrive->MoveToPos(pos);
	if (has_power) {
		Robot::autodrive->SetMaxPower(max_power);
	} else {
		// Reset to default max power: 0.75, as specified in AutoDrive.cpp
		Robot::autodrive->SetMaxPower();
	}
}
