#include "OI.h"

#include <WPILib.h>
#include <Commands/IntakeOn.h>
#include <Commands/IntakeInvert.h>
#include <Commands/DriveForward.h>

OI::OI() {
	// Process operator interface input here.
	joy = new Joystick(0);
	B2 = new frc::JoystickButton(joy,2);
	B2->WhileHeld(new  DriveForward());
	B7 = new frc::JoystickButton(joy,2);
	B7->WhileHeld(new  IntakeOn());
	B8 = new frc::JoystickButton(joy,2);
	B8->WhileHeld(new  IntakeInvert());

}

Joystick* OI::GetJoystick() {
	return joy;
}
