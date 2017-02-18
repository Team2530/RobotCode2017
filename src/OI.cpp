#include "OI.h"

#include <Commands/SlowLift.h>
#include <Commands/FastLift.h>
#include <WPILib.h>
#include <Commands/IntakeOn.h>
#include <Commands/IntakeInvert.h>
#include <Commands/DriveForward.h>

#include <Commands/OrientRobot.h>

#include <Commands/IntakeOn.h>
#include <Commands/IntakeInvert.h>
#include <Commands/Dump.h>
#include <Commands/ResetDump.h>
#include <Commands/LEDControl.h>
#include <Commands/DriveLeftSideForward.h>
#include <Commands/MecanumDriveFieldOriented.h>

#include <Commands/DriveToPosition.h>

#include <Commands/MecanumDriveFieldOriented.h>
#include <Commands/SlowLift.h>

OI::OI() {
	// Process operator interface input here.
	joy = new Joystick(0);

	B1 = new frc::JoystickButton(joy,1);
	B1->WhenPressed(new LEDControl(true));
	B1->WhenReleased(new LEDControl(false));

	B2 = new frc::JoystickButton(joy, 2);
	B2->WhileHeld(new  DriveToPosition(&testx,&testy));
	testx=0;
	testy=50;

	B3 = new frc::JoystickButton(joy,3);
	B3->WhileHeld(new  DriveForward());
	B4 = new frc::JoystickButton(joy,4);
	B4->WhileHeld(new  DriveLeftSideForward()); //Taco side acts as front

	B6 = new frc::JoystickButton(joy, 6);
	B6->WhenPressed(new OrientRobot(&ninetyDegrees));
	B7 = new frc::JoystickButton(joy,7);
	//B7->WhileHeld(new  IntakeOn());
	B8 = new frc::JoystickButton(joy,8);
	B8->WhileHeld(new  IntakeInvert());

	B11 = new frc::JoystickButton(joy, 11);
	B11->WhenPressed(new MecanumDriveFieldOriented());


	ahrs = new AHRS(SPI::Port::kMXP);
	ahrs->Reset();

	Xbox = new frc::XboxController(1);
	A = new frc::JoystickButton(Xbox, 1);
	A->WhileHeld(new IntakeOn());
	B = new frc::JoystickButton(Xbox, 2);
	//B->WhenPressed(new IntakeOff());
	X = new frc::JoystickButton(Xbox, 3);
	Y = new frc::JoystickButton(Xbox, 4);
	Y->WhenPressed(new IntakeInvert());
	LB = new frc::JoystickButton(Xbox, 5);
	LB->WhileHeld(new SlowLift());
	RB = new frc::JoystickButton(Xbox, 6);
	RB->WhileHeld(new FastLift());
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
