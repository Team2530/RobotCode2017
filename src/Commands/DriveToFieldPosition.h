#ifndef DriveToFieldPosition_H
#define DriveToFieldPosition_H

#include "AutoDriveBase.h"
#include "FieldPositions/FieldPosition.h"

class DriveToFieldPosition : public AutoDriveBase {
public:
	DriveToFieldPosition(FieldPosition *FP);
	DriveToFieldPosition(FieldPosition *FP, double power);
	void UpdatePosition() override;
private:
	FieldPosition *FieldP;
	bool has_power;
	double max_power;
};

#endif  // DriveToFieldPosition_H
