#ifndef MecanumDriveWithJoystick_H
#define MecanumDriveWithJoystick_H

#include <Commands/Command.h>

class MecanumDriveWithJoystick : public Command {
public:
	MecanumDriveWithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MecanumDriveWithJoystick_H
