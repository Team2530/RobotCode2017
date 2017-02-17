#ifndef DeliverGear_H
#define DeliverGear_H

#include <Commands/Command.h>

class DeliverGear : public Command {
public:
	DeliverGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DeliverGear_H
