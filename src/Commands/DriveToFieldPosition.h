#ifndef DriveToFieldPosition_H
#define DriveToFieldPosition_H
#include "FieldPositions/FieldPosition.h"
#include "Commands/Command.h"

class DriveToFieldPosition : public Command {
public:
	DriveToFieldPosition(FieldPosition *FP);
	DriveToFieldPosition(FieldPosition *FP, double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	FieldPosition *FieldP;
	bool has_power;
	double max_power;
};

#endif  // DriveToFieldPosition_H
