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
	// This method needs to be implemented in each derived class
	// Should set the goal position on Robot::autodrive
	// with either AutoDrive::MoveToPos (recommended)
	// or directly with AutoDrive::Set (not recommended).
	// May also do other calculations.
	// May also call AutoDrive::SetMaxPower,
	// which will otherwise be reset to the default.
	// Called once during initialization
	virtual void UpdatePosition() = 0;
};

#endif  // AutoDriveBase_H
