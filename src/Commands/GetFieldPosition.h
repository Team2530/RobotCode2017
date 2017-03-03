#ifndef GetFieldPosition_H
#define GetFieldPosition_H

#include <Commands/Command.h>

// This command is the default command of the Tracker.
// It reads the encoders and gyro to track the field position.


class GetFieldPosition : public Command {
public:
	GetFieldPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GetFieldPosition_H
