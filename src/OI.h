#ifndef OI_H
#define OI_H

#include <Joystick.h>

class OI {
public:
	OI();
	Joystick* GetJoystick();
private:
	Joystick* joy;
};

#endif  // OI_H
