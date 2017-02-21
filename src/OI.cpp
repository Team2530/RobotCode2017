#include "OI.h"

#include <WPILib.h>

//JOYSTICK
#include <Commands/LEDControl.h>				//Please do not include the same file multiple times!
#include <Commands/DriveToPosition.h>
#include <Commands/DriveLeft.h>
#include <Commands/DriveBackSideForward.h>
#include <Commands/DriveRightSideForward.h>
#include <Commands/DriveLeftSideForward.h>

#include <Commands/MecanumDriveWithJoystick.h>

#include <Commands/DriveForward.h>
#include <Commands/OrientRobot.h>

//Xbox
#include <Commands/IntakeOn.h>
#include <Commands/LEDToggle.h>
#include <Commands/Dump.h>
#include <Commands/IntakeInvert.h>
#include <Commands/SlowLift.h>
#include <Commands/FastLift.h>
#include <Commands/AimCameratoLift.h>
#include <Commands/AimCameratoTaco.h>

#include <Commands/ResetDump.h>
#include <Commands/GoTo.h>
#include <Commands/ResetTracker.h>
#include <Commands/MoveBy.h>
#include <Commands/RotateTo.h>

OI::OI() {
	// Process operator interface input here.
	joy = new Joystick(0);

	B1 = new frc::JoystickButton(joy,1);				//Please do not have more than one button do the exact same command!
	B1->WhenPressed(new LEDControl(true));
	B1->WhenReleased(new LEDControl(false));
	B2 = new frc::JoystickButton(joy, 2);
	B2->WhileHeld(new DriveToPosition(&testx,&testy));
	testx=0;											//currently testing these coordinates
	testy=100;

	B3 = new frc::JoystickButton(joy, 3);      //Drives towards the peg when positioned with it
	B3->WhileHeld(new DriveLeft());
	B4 = new frc::JoystickButton(joy,4);	   //Lifter side acts as front
	B4->WhileHeld(new DriveBackSideForward());
	B5 = new frc::JoystickButton(joy,5);	   //Dumper side acts as front
	B5->WhileHeld(new DriveRightSideForward());
	B6 = new frc::JoystickButton(joy,6);	   //Taco side acts as front
	B6->WhileHeld(new DriveLeftSideForward());

	B9 = new frc::JoystickButton(joy, 9);
	B9->WhileHeld(new MecanumDriveWithJoystick());

	B11 = new frc::JoystickButton(joy,11);
	B11->WhileHeld(new DriveForward());
	B12 = new frc::JoystickButton(joy, 12);
	B12->WhenPressed(new OrientRobot(&ninetyDegrees));

	ahrs = new AHRS(SPI::Port::kMXP);
	ahrs->Reset();

	Xbox = new frc::XboxController(1);
	A = new frc::JoystickButton(Xbox, 1);
	A->WhileHeld(new MoveBy(0, -10));
	B = new frc::JoystickButton(Xbox, 2);
	B->WhileHeld(new MoveBy(10, 0));
	X = new frc::JoystickButton(Xbox, 3);
	X->WhileHeld(new MoveBy(-10, 0));
	Y = new frc::JoystickButton(Xbox, 4);
	Y->WhileHeld(new MoveBy(0, 10));
	LB = new frc::JoystickButton(Xbox, 5);
	LB->WhileHeld(new SlowLift());
	RB = new frc::JoystickButton(Xbox, 6);
	RB->WhileHeld(new FastLift());
	Back = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kBackbutton);
	Back->WhenPressed(new ResetTracker());
	Start = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kStartbutton);
	Start->WhileHeld(new GoTo(0,0));
	RS = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kRSbutton);
	RS->WhileHeld(new RotateTo(0));
}

Joystick* OI::GetJoystick() {
	return joy;
}

AHRS* OI::GetAHRS() {
	return ahrs;
}
