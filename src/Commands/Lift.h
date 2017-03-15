#ifndef Lift_H
#define Lift_H

#include "Robot.h"

class Lift : public Command {
public:
	Lift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Lift_H
