#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <XboxController.h>
#include "WPILib.h"
#include <Buttons/JoystickButton.h>
#include "Subsystems/ControllerConstants.h"
#include <AHRS.h>

class OI {
public:
	OI();
	Joystick* GetJoystick();
	AHRS* GetAHRS();
private:
	Joystick* joy;
	JoystickButton *B1;  //LED Control
	JoystickButton *B2;  //DriveLeft
	JoystickButton *B3;  //MecanumDriveWithJoystick
	JoystickButton *B4;  //DriveBackSideForward
	JoystickButton *B5;  //DriveRightSideForward
	JoystickButton *B6;  //DriveLeftSideForward

	JoystickButton *B7;  //Unused
	JoystickButton *B8;  //Unused

	JoystickButton *B9;  //DriveToPosition Test

	JoystickButton *B10; //Unused

	JoystickButton *B11; //DriveForward
	JoystickButton *B12; //OrientRobotNinetyDegrees

	XboxController *Xbox;
	JoystickButton *A; 	 // intake on
	JoystickButton *B;   // LED
	JoystickButton *Y;   // intake invert
	JoystickButton *X;   // dump
	JoystickButton *RB;  // fast lift
	JoystickButton *LB;  // slow lift
	JoystickButton *Back;// camera faces rope
	JoystickButton *Start;// camera faces peg

	JoystickButton *LS;  //Unused

	JoystickButton *RS;  //Reset Dump

	AHRS* ahrs;			 //navX MXP

	double testx;
	double testy;

	double ninetyDegrees = 90.0;
};

#endif  // OI_H
