#ifndef DeliverMiddleGear_H
#define DeliverMiddleGear_H

#include <Commands/Command.h>

class DeliverMiddleGear : public Command {
public:
	DeliverMiddleGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DeliverMiddleGear_H
