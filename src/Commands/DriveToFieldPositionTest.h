#ifndef DriveToFieldPositionTest_H					//This file is unnecessary! Use DriveToFieldPosition.h instead!
#define DriveToFieldPositionTest_H
#include "FieldPositions/FieldPosition.h"
#include "Commands/Command.h"

class DriveToFieldPositionTest : public Command {
public:
	DriveToFieldPositionTest(FieldPosition *FP);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	FieldPosition *FieldP;
};

#endif  // DriveToFieldPosition_H
