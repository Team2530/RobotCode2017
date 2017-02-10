#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>
#include <AHRS.h>

class OI {
public:
	OI();
	Joystick* GetJoystick();
private:
	Joystick* joy;
	JoystickButton *B2;
	JoystickButton *B7;
	JoystickButton *B8;

};

#endif  // OI_H
