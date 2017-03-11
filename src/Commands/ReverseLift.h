#ifndef ReverseLift_H
#define ReverseLift_H

#include <Commands/Command.h>
#include "Robot.h"

class ReverseLift : public Command {
public:
	ReverseLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ReverseLift_H
