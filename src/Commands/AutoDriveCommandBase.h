#ifndef AutoDriveBase_H
#define AutoDriveBase_H

#include <Commands/Command.h>

class AutoDriveCommandBase : public frc::Command {
public:
	AutoDriveCommandBase();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	virtual void UpdatePosition() = 0;
};

#endif  // AutoDriveBase_H
