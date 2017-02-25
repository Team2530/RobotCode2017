#ifndef DriveToFieldPosition_H
#define DriveToFieldPosition_H
#include "FieldPosition.h"
#include "Commands/Command.h"

class DriveToFieldPosition : public Command {
public:
	DriveToFieldPosition(FieldPosition *FP);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	FieldPosition *FieldP;
};

#endif  // DriveToFieldPosition_H
