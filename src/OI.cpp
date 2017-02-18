#include "OI.h"

#include <WPILib.h>

//JOYSTICK
#include <Commands/LEDControl.h>				//do not include the same file multiple times
#include <Commands/DriveToPosition.h>
#include <Commands/MecanumDriveFieldOriented.h>
#include <Commands/DriveLeftSideForward.h>
#include <Commands/DriveLeft.h>
#include <Commands/DriveBackSideForward.h>

#include <Commands/DriveForward.h>
#include <Commands/OrientRobot.h>

#include <Commands/IntakeOn.h>
#include <Commands/LEDToggle.h>
#include <Commands/IntakeOn.h>
#include <Commands/IntakeInvert.h>

#include <Commands/Dump.h>
#include <Commands/ResetDump.h>

#include <Commands/AimCameratoLift.h>
#include <Commands/AimCameratoTaco.h>

OI::OI() {
	// Process operator interface input here.
	joy = new Joystick(0);

	B1 = new frc::JoystickButton(joy,1);
	B1->WhenPressed(new LEDControl(true));
	B1->WhenReleased(new LEDControl(false));

	B2 = new frc::JoystickButton(joy, 2);
	B2->WhileHeld(new  DriveToPosition(&testx,&testy));
	testx=0;
	testy=100;

	B3 = new frc::JoystickButton(joy, 3);
	B3->WhileHeld(new MecanumDriveFieldOriented());
	B4 = new frc::JoystickButton(joy,4);
	B4->WhileHeld(new  DriveLeftSideForward()); //Taco side acts as front
	B5 = new frc::JoystickButton(joy,5);
	B5->WhileHeld(new  DriveLeft());
	B6 = new frc::JoystickButton(joy,6);
	B6->WhileHeld(new DriveBackSideForward());

	B11 = new frc::JoystickButton(joy,11);
	B11->WhileHeld(new  DriveForward());
	B12 = new frc::JoystickButton(joy, 12);
	B12->WhenPressed(new OrientRobot(&ninetyDegrees));

	ahrs = new AHRS(SPI::Port::kMXP);
	ahrs->Reset();

	Xbox = new frc::XboxController(1);
	A = new frc::JoystickButton(Xbox, 1);
	A->ToggleWhenPressed(new IntakeOn());
	B = new frc::JoystickButton(Xbox, 2);
	B->WhenPressed(new LEDToggle());
	X = new frc::JoystickButton(Xbox, 3);
	X->WhenPressed(new IntakeOff());
	Y = new frc::JoystickButton(Xbox, 4);
	Y->ToggleWhenPressed(new IntakeInvert());
	LB = new frc::JoystickButton(Xbox, 5);
	LB->WhileHeld(new SlowLift());
	RB = new frc::JoystickButton(Xbox, 6);
	RB->WhileHeld(new FastLift());
	Back = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kBackbutton);
	Back->WhenPressed(new AimCameratoLift());
	Start = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kStartbutton);
	Start->WhenPressed(new AimCameratoTaco());
}

Joystick* OI::GetJoystick() {
	return joy;
}

AHRS* OI::GetAHRS() {
	return ahrs;
}
