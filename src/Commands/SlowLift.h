#ifndef SlowLift_H
#define SlowLift_H

#include <Commands/Command.h>
#include "Robot.h"

class SlowLift : public Command {
public:
	SlowLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Lift_H
