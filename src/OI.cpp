#include "OI.h"

#include <WPILib.h>

OI::OI() {
	// Process operator interface input here.
	joy = new Joystick(0);
}

Joystick* OI::GetJoystick() {
	return joy;
}
