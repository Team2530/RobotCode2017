#ifndef GetVision_H
#define GetVision_H

#include "AutoDriveCommandBase.h"
#include "../FieldPositions/FieldPosition.h"

class GetVision : public AutoDriveCommandBase {
private:
	FieldPosition* fp;
public:
	GetVision(FieldPosition* fieldposition);
	void UpdatePosition();
	bool IsFinished();
};

#endif  // GetVision_H
