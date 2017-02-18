#ifndef FastLift_H
#define FastLift_H

#include <Commands/Command.h>
#include "Robot.h"

class FastLift : public Command {
public:
	FastLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Lift_H
