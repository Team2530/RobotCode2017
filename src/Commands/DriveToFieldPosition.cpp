#include "DriveToFieldPosition.h"
#include "../Robot.h"

DriveToFieldPosition::DriveToFieldPosition(FieldPosition *FP) {
	FieldP = FP;
	has_power = false;
}
DriveToFieldPosition::DriveToFieldPosition(FieldPosition *FP, double power) {
	FieldP = FP;
	has_power = true;
	max_power = power;
}

// Called just before this Command runs the first time
void DriveToFieldPosition::UpdatePosition() {
	Robot::autodrive->Set(FieldP->GetX(), FieldP->GetY(), FieldP->GetR());
	if (has_power) {
		Robot::autodrive->SetMaxPower(max_power);
	} else {
		Robot::autodrive->SetMaxPower();
	}
}
