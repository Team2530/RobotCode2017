#ifndef MoveBasedOnVision_H
#define MoveBasedOnVision_H

#include <Commands/Command.h>

class MoveBasedOnVision : public frc::Command {
public:
	MoveBasedOnVision();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveBasedOnVision_H
