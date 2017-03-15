#ifndef MoveBasedOnVision_H
#define MoveBasedOnVision_H

#include <Commands/Command.h>
#include "../FieldPositions/FieldPosition.h"

class MoveBasedOnVision : public frc::Command {
private:
	double goal;
	FieldPosition* fp;
public:
	MoveBasedOnVision(double distance, FieldPosition* fieldposition);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveBasedOnVision_H
