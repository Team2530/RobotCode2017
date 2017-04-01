#include "DriveToFieldPosition.h"
#include "../Robot.h"

DriveToFieldPosition::DriveToFieldPosition(FieldPosition *FP) {
	FieldP = FP;
	has_power = false;
}
DriveToFieldPosition::DriveToFieldPosition(FieldPosition *FP, double speed) {
	FieldP = FP;
	has_power = true;
	max_power = speed;
}

// Called just before this Command runs the first time
void DriveToFieldPosition::UpdatePosition() {
	Robot::autodrive->Set(FieldP->GetX(), FieldP->GetY(), FieldP->GetR());
	if (has_power) {
		Robot::autodrive->SetMaxPower(max_power);
	} else {
		// Reset to default max power: 0.75, as specified in AutoDrive.cpp
		Robot::autodrive->SetMaxPower();
	}
}
