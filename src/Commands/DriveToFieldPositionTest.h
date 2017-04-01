#ifndef DriveToFieldPositionTest_H
#define DriveToFieldPositionTest_H

#include <Commands/AutoDriveCommandBase.h>
#include "FieldPositions/FieldPosition.h"

class DriveToFieldPositionTest : public AutoDriveCommandBase {
public:
	DriveToFieldPositionTest(FieldPosition *FP);
	DriveToFieldPositionTest(FieldPosition *FP, double speed);
	void UpdatePosition() override;
	bool IsFinished() override;
private:
	FieldPosition *FieldP;
	bool has_power;
	double max_power;
};

#endif  // DriveToFieldPositionTest_H
