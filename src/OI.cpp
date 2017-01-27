#include "OI.h"

#include <WPILib.h>

#include <Commands/DriveForward.h>

OI::OI() {
	// Process operator interface input here.
	joy = new Joystick(0);
	B2 = new frc::JoystickButton(joy,2);
	B2->WhileHeld(new  DriveForward());
}

Joystick* OI::GetJoystick() {
	return joy;
}
