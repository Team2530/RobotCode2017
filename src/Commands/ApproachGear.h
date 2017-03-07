#ifndef ApproachGear_H
#define ApproachGear_H

#include <Commands/Command.h>

class ApproachGear : public Command {
public:
	ApproachGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ApproachGear_H
