#ifndef MoveBasedOnVision_H
#define MoveBasedOnVision_H

#include "AutoDriveCommandBase.h"
#include "../FieldPositions/FieldPosition.h"

class MoveBasedOnVision : public AutoDriveCommandBase {
private:
	double goal;
	FieldPosition* fp;
public:
	MoveBasedOnVision(double distance, FieldPosition* fieldposition);
	void UpdatePosition();
	void End();
	void Interrupted();
};

#endif  // MoveBasedOnVision_H
