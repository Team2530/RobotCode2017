#include "OI.h"

#include <WPILib.h>

//JOYSTICK
#include <Commands/LEDControl.h>				//Please do not include the same file multiple times!
#include <Commands/DriveLeft.h>
#include <Commands/MecanumDriveWithJoystick.h>
#include <Commands/DriveBackSideForward.h>
#include <Commands/DriveLeftSideForward.h>
#include <Commands/DriveRightSideForward.h>

#include <Commands/DriveToPosition.h>

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
#include <Commands/ResetTracker.h>

#include <Commands/DriveToPosition.h>
#include <Positions/RobotRelative.h>
#include <Positions/Absolute.h>
#include <Positions/AbsoluteAngle.h>

#include <Positions/FieldRelative.h>

OI::OI() {
	// Process operator interface input here.
	joy = new Joystick(0);

	B1 = new frc::JoystickButton(joy,1);				//Please do not have more than one button do the exact same command!
	B1->WhenPressed(new LEDControl(true));
	B1->WhenReleased(new LEDControl(false));
	B2 = new frc::JoystickButton(joy, 2);				//Moves towards the peg when the taco is already aligned with the peg!
	B2->WhileHeld(new DriveLeft());
	B3 = new frc::JoystickButton(joy, 3);
	B3->WhileHeld(new MecanumDriveWithJoystick());
	B4 = new frc::JoystickButton(joy,4);				//Has the lifter side act as the front!
	B4->WhileHeld(new DriveBackSideForward());
	B5 = new frc::JoystickButton(joy,5);				//Has the taco side act as the front!
	B5->WhileHeld(new DriveLeftSideForward());
	B6 = new frc::JoystickButton(joy,6);				//Has the dumper side act as the front!
	B6->WhileHeld(new DriveRightSideForward());

	B9 = new frc::JoystickButton(joy, 9);
	B9->WhileHeld(new DriveToPosition(new Absolute(0, 0)));

	ahrs = new AHRS(SPI::Port::kMXP);
	ahrs->Reset();

	Xbox = new frc::XboxController(1);
	// Button configuration for testing PID controllers and such
	/**/
	A = new frc::JoystickButton(Xbox, 1);
	A->WhileHeld(new DriveToPosition(new RobotRelative(0, -10)));
	B = new frc::JoystickButton(Xbox, 2);
	B->WhileHeld(new DriveToPosition(new RobotRelative(10, 0)));
	X = new frc::JoystickButton(Xbox, 3);
	X->WhileHeld(new DriveToPosition(new RobotRelative(-10, 0)));
	Y = new frc::JoystickButton(Xbox, 4);
	Y->WhileHeld(new DriveToPosition(new RobotRelative(0, 10)));
	LB = new frc::JoystickButton(Xbox, 5);
	LB->WhileHeld(new SlowLift());
	RB = new frc::JoystickButton(Xbox, 6);
	RB->WhileHeld(new FastLift());
	Back = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kBackbutton);
	Back->WhenPressed(new ResetTracker());
	Start = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kStartbutton);
	Start->WhileHeld(new DriveToPosition(new Absolute(0,0)));
	RS = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kRSbutton);
	RS->WhenPressed(new DriveToPosition(new AbsoluteAngle(0)));
	/*/
	// Button configuration for competition driving
	A = new frc::JoystickButton(Xbox, 1);
	A->ToggleWhenPressed(new IntakeOn());
	B = new frc::JoystickButton(Xbox, 2);
	B->WhenPressed(new LEDToggle());
	X = new frc::JoystickButton(Xbox, 3);
	X->WhileHeld(new Dump());
	Y = new frc::JoystickButton(Xbox, 4);
	Y->ToggleWhenPressed(new IntakeInvert());
	LB = new frc::JoystickButton(Xbox, 5);
	LB->WhileHeld(new SlowLift());
	RB = new frc::JoystickButton(Xbox, 6);
	RB->WhileHeld(new FastLift());
	Back = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kBackbutton);
	Back->WhileHeld(new AimCameratoLift());
	Start = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kStartbutton);
	Start->WhileHeld(new AimCameratoTaco());
	RS = new frc::JoystickButton(Xbox, ControllerConstants::xBoxButtonMap::kRSbutton);
	RS->WhileHeld(new ResetDump());
	*/
}

Joystick* OI::GetJoystick() {
	return joy;
}

AHRS* OI::GetAHRS() {
	return ahrs;
}
