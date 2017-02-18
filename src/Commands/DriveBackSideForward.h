#ifndef DriveBackSideForward_H
#define DriveBackSideForward_H

#include <Commands/Command.h>

class DriveBackSideForward : public Command {
public:
	DriveBackSideForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveBackSideForward_H