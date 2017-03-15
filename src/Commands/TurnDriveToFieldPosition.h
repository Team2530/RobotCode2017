#ifndef TurnDriveToFieldPosition_H
#define TurnDriveToFieldPosition_H
#include "FieldPositions/FieldPosition.h"
#include "Commands/Command.h"
#include <math.h>

class TurnDriveToFieldPosition : public Command {
public:
	TurnDriveToFieldPosition(FieldPosition *FP);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double GetCurrentPositionX();
	double GetCurrentPositionY();
private:
	double goalPositionX;
	double goalPositionY;
	double currentPositionX; // Right
	double currentPositionY; // Forward
	FieldPosition *FieldP;
};

#endif  // TurnDriveToFieldPosition_H
