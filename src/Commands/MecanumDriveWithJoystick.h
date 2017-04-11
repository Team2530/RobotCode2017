#ifndef MecanumDriveWithJoystick_H
#define MecanumDriveWithJoystick_H

#include <Commands/Command.h>
#include "../Orientation.h"

class MecanumDriveWithJoystick : public Command {
private:
	Orientation orientation;
public:
	MecanumDriveWithJoystick(Orientation orient=FRONT_FORWARD);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MecanumDriveWithJoystick_H
