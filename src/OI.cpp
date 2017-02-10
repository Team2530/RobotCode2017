#include "OI.h"

#include <WPILib.h>
#include <Commands/IntakeOn.h>
#include <Commands/IntakeInvert.h>
#include <Commands/DriveForward.h>
#include <Commands/OrientRobot.h>

OI::OI() {
	// Process operator interface input here.
	joy = new Joystick(0);
	B2 = new frc::JoystickButton(joy,2);
	B2->WhileHeld(new  DriveForward());
	B7 = new frc::JoystickButton(joy,7);
	B7->WhileHeld(new  IntakeOn());
	B8 = new frc::JoystickButton(joy,8);
	B8->WhileHeld(new  IntakeInvert());
	ahrs= new AHRS(SerialPort::kMXP);
	B6 = new frc::JoystickButton(joy, 6);
	B6->WhenPressed(new OrientRobot(90));

}

Joystick* OI::GetJoystick() {
	return joy;
}

AHRS* OI::GetAHRS() {
	return ahrs;
}
