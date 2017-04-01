#include "DriveToFieldPositionTest.h"																	//Does not stop!
#include "../Robot.h"

DriveToFieldPositionTest::DriveToFieldPositionTest(FieldPosition *FP) {
	FieldP = FP;
	has_power = false;
}
DriveToFieldPositionTest::DriveToFieldPositionTest(FieldPosition *FP, double speed) {
	FieldP = FP;
	has_power = true;
	max_power = speed;
}

// Called just before this Command runs the first time
void DriveToFieldPositionTest::UpdatePosition() {
	Robot::autodrive->Set(FieldP->GetX(), FieldP->GetY(), FieldP->GetR());
	if (has_power) {
		Robot::autodrive->SetMaxPower(max_power);
	} else {
		// Reset to default max power: 0.75, as specified in AutoDrive.cpp
		Robot::autodrive->SetMaxPower();
	}
}

// Return false to keep the command running to see PID oscillation
bool DriveToFieldPositionTest::IsFinished() {
	return false;
}
