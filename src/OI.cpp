#include "OI.h"

#include <WPILib.h>
#include <Commands/IntakeOn.h>
#include <Commands/IntakeInvert.h>
#include <Commands/DriveForward.h>

#include <Commands/OrientRobot.h>

#include <Commands/IntakeOn.h>
#include <Commands/IntakeInvert.h>
#include <Commands/Dump.h>
#include <Commands/ResetDump.h>

#include <Commands/DriveLeftSideForward.h>


OI::OI() {
	// Process operator interface input here.
	joy = new Joystick(0);

	B3 = new frc::JoystickButton(joy,3);
	B3->WhileHeld(new  DriveForward());
	B4 = new frc::JoystickButton(joy,4);
	B4->WhileHeld(new  DriveLeftSideForward());
	B7 = new frc::JoystickButton(joy,7);
	B7->WhileHeld(new  IntakeOn());
	B8 = new frc::JoystickButton(joy,8);
	B8->WhileHeld(new  IntakeInvert());

	ahrs = new AHRS(SPI::Port::kMXP);
	ahrs->Reset();
	B6 = new frc::JoystickButton(joy, 6);
	B6->WhenPressed(new OrientRobot(&ninetyDegrees));
	B6->WhenPressed(new OrientRobot(90.0));
	B11 = new frc::JoystickButton(joy, 11);
	B11->WhenPressed(new MecanumDriveFieldOriented());
/*
	B9 = new frc::JoystickButton(joy,9);
	//B9->WhileHeld(new  Dump());
	B10 = new frc::JoystickButton(joy,10);
//	B10->WhileHeld(new  ResetDump());
*/
}

Joystick* OI::GetJoystick() {
	return joy;
}

AHRS* OI::GetAHRS() {
	return ahrs;
}
