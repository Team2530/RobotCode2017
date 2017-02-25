#ifndef DriveForward_H
#define DriveForward_H

#include <Commands/Command.h>

class DriveForward : public Command {
public:
	DriveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForward_H
