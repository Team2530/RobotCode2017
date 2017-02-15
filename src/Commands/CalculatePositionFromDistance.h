#ifndef CalculatePositionFromDistance_H
#define CalculatePositionFromDistance_H

#include "Commands/Command.h"

class CalculatePositionFromDistance : public Command {
public:
	CalculatePositionFromDistance();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CalculatePositionFromDistance_H
