#ifndef DriveToPosition_H
#define DriveToPosition_H

#include "AutoDriveBase.h"
#include "../Positions/Position.h"

class DriveToPosition : public AutoDriveBase {
public:
	DriveToPosition(Position* pos);
	void UpdatePosition() override;
private:
	Position* pos;
};

#endif  // DriveToPosition_H
