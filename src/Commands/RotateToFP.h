#ifndef RotateToFP_H
#define RotateToFP_H

#include <Commands/Command.h>

class RotateToFP : public Command {
public:
	RotateToFP();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RotateToFP_H
