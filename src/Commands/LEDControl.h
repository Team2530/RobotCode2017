#ifndef LEDControl_H
#define LEDControl_H

#include "../Robot.h"

class LEDControl : public Command {
private:
	bool value;
public:
	LEDControl(bool on);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LEDControl_H
