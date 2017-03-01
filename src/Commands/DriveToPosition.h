#ifndef DriveToPosition_H
#define DriveToPosition_H

#include <Commands/Command.h>
#include "../Positions/Position.h"

class DriveToPosition : public frc::Command {
public:
	DriveToPosition(Position* pos);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Position* pos;
};

#endif  // DriveToPosition_H
