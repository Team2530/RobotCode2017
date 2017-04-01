#ifndef DriveToFieldPosition_H
#define DriveToFieldPosition_H

#include <Commands/AutoDriveCommandBase.h>
#include "FieldPositions/FieldPosition.h"

class DriveToFieldPosition : public AutoDriveCommandBase {
public:
	DriveToFieldPosition(FieldPosition *FP);
	DriveToFieldPosition(FieldPosition *FP, double speed);
	void UpdatePosition() override;
private:
	FieldPosition *FieldP;
	bool has_power;
	double max_power;
};

#endif  // DriveToFieldPosition_H
