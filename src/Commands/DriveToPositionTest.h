#ifndef DriveToFieldPositionTest_H
#define DriveToFieldPositionTest_H

#include <Commands/DriveToPosition.h>
#include "FieldPositions/FieldPosition.h"

class DriveToPositionTest : public DriveToPosition {
public:
	DriveToPositionTest(Position* pos);
	DriveToPositionTest(Position* pos, double speed);
	bool IsFinished() override;
};

#endif  // DriveToFieldPositionTest_H
