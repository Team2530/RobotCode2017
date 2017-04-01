#ifndef DriveToPosition_H
#define DriveToPosition_H

#include <Commands/AutoDriveCommandBase.h>
#include "../Positions/Position.h"

class DriveToPosition : public AutoDriveCommandBase {
public:
	DriveToPosition(Position* pos);
	DriveToPosition(Position* pos, double speed);
	void UpdatePosition() override;
private:
	Position* pos;
	bool has_power;
	double max_power;
};

#endif  // DriveToPosition_H
