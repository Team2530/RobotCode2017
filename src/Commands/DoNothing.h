#ifndef DoNothing_H
#define DoNothing_H

#include <Commands/Command.h>


class DoNothing : public Command {
public:
	DoNothing();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DoNothing_H
