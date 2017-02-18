#ifndef Lift_H
#define Lift_H

#include <Commands/Command.h>

class Lift : public Commands {
public:
	Lift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Lift_H
