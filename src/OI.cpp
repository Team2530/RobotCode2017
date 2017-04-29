//JOYSTICK
#include <Commands/LEDControl.h>				//Please do not include the same file multiple times!
#include <Commands/DriveLeft.h>
#include <Commands/MecanumDriveWithJoystick.h>

#include <Commands/GetVision.h>
#include <Commands/MoveBasedOnVision.h>
#include <Commands/DriveToPosition.h>
#include <Commands/DoNothing.h>

//Xbox
#include <Commands/LEDToggle.h>
#include <Commands/Dump.h>
#include <Commands/SlowLift.h>
#include <Commands/FastLift.h>
#include <Commands/AimCameratoLift.h>
#include <Commands/AimCameratoTaco.h>
#include <Commands/AimCameratoFrontTaco.h>

#include <Commands/ResetDump.h>
#include <Commands/ResetTracker.h>

#include <Commands/DriveToPositionTest.h>
#include <Positions/RobotRelative.h>
#include <Positions/Absolute.h>
#include <Positions/AbsoluteAngle.h>

#include <Positions/FieldRelative.h>
#include <FieldPositions/GearFieldPosition.h>

OI::OI() {
	//FieldPosition* gear = new GearFieldPosition();

	// Process operator interface input here.
	joy = new Joystick(0);

	B1 = new frc::JoystickButton(joy,1);
	B1->WhileHeld(new DoNothing(true));
	//Moves towards the peg when the taco is already aligned with the peg!
	B2 = new frc::JoystickButton(joy, 2);
	B2->WhileHeld(new DriveToPosition(new RobotRelative(-100, 0), 0.5));
	B3 = new frc::JoystickButton(joy, 3);
	B3->WhileHeld(new MecanumDriveWithJoystick());
	B4 = new frc::JoystickButton(joy,4);
	B4->WhileHeld(new MecanumDriveWithJoystick(CLIMBER_FORWARD));
	B5 = new frc::JoystickButton(joy,5);
	B5->WhileHeld(new MecanumDriveWithJoystick(TAKKO_FORWARD));
	B6 = new frc::JoystickButton(joy,6);
	B6->WhileHeld(new MecanumDriveWithJoystick(DUMP_FORWARD));
	B7 = new frc::JoystickButton(joy, 7);
	B7->WhenPressed(new MoveBasedOnVision(36, nullptr));
	B8 = new frc::JoystickButton(joy, 8);
	//B8->WhenPressed(new MoveBasedOnVision(24, nullptr));
	B9 = new frc::JoystickButton(joy, 9);
	//B9->WhileHeld(new DriveToPosition(new Absolute(0, 0)));
	B9->WhenPressed(new MoveBasedOnVision(30, nullptr));
	B11 = new frc::JoystickButton(joy,11);
	B11->WhenPressed(new MoveBasedOnVision(24, nullptr));

	Xbox = new frc::XboxController(1);
	const double testdistance = 20;
	// Button configuration for testing PID controllers and such
	/*
	A = new frc::JoystickButton(Xbox, 1);
	A->WhenPressed(new DriveToPosition(new RobotRelative(0, -testdistance), 0.3));
	B = new frc::JoystickButton(Xbox, 2);
	B->WhenPressed(new DriveToPosition(new RobotRelative(testdistance, 0), 0.3));
	X = new frc::JoystickButton(Xbox, 3);
	X->WhenPressed(new DriveToPosition(new RobotRelative(-testdistance, 0), 0.3));
	Y = new frc::JoystickButton(Xbox, 4);
	Y->WhenPressed(new DriveToPosition(new RobotRelative(0, testdistance), 0.3));
	LB = new frc::JoystickButton(Xbox, 5);
	LB->WhileHeld(new SlowLift());
	RB = new frc::JoystickButton(Xbox, 6);
	RB->WhileHeld(new FastLift());
	Back = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kBackbutton);
	Back->WhenPressed(new ResetTracker());
	Start = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kStartbutton);
	Start->WhenPressed(new DriveToPositionTest(new Absolute(0,0)));
	RS = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kRSbutton);
	RS->WhenPressed(new DriveToPositionTest(new AbsoluteAngle(0)));
	/*/
	// Button configuration for competition driving
	A = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kAbutton);
	A->ToggleWhenPressed(new LEDToggle());
	B = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kBbutton);
	B->WhenPressed(new AimCameratoFrontTaco());
	X = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kXbutton);
	X->WhileHeld(new AimCameratoTaco());
	Y = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kYbutton);
	Y->WhenPressed(new DriveToPositionTest(new RobotRelative(0, testdistance), 0.3));
	LB = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kLBbutton);
	LB->WhileHeld(new SlowLift());
	RB = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kRBbutton);
	RB->WhileHeld(new FastLift());
	Back = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kBackbutton);
	Back->WhileHeld(new Dump());
	Start = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kStartbutton);
	Start->WhileHeld(new ResetDump());
	RS = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kRSbutton);
	RS->WhileHeld(new ResetTracker());
	LS = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kLSbutton);
	LS->WhenPressed(new GetVision(nullptr));
	//*/
}

Joystick* OI::GetJoystick() {
	return joy;
}
