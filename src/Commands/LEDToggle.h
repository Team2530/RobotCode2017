#ifndef LEDTOGGLE_H
#define LEDTOGGLE_H

#include <Commands/Command.h>

class LEDToggle : public Command {
public:
	LEDToggle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LEDTOGGLE_H
