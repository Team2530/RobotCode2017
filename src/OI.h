#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>
#include <Subsystems/AHRS.h>

class OI {
public:
	OI();
	Joystick* GetJoystick();
	AHRS* GetAHRS();
private:
	Joystick* joy;
	JoystickButton *B2;
	JoystickButton *B6;
	JoystickButton *B7;
	JoystickButton *B8;
	AHRS* ahrs;
};

#endif  // OI_H
