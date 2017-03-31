#include "DriveToPosition.h"

#include "../Robot.h"

DriveToPosition::DriveToPosition(Position* p) {
	pos = p;
}

// Called just before this Command runs the first time
void DriveToPosition::UpdatePosition() {
	Robot::autodrive->MoveToPos(pos);
}
