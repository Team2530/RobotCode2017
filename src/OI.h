#ifndef OI_H
#define OI_H

#include "Subsystems/ControllerConstants.h"
#include <AHRS.h>

class OI {
public:
	OI();
	Joystick* GetJoystick();
private:
	Joystick* joy;
	JoystickButton *B1;  //LED Control
	JoystickButton *B2;  //DriveLeft in a new form
	JoystickButton *B3;  //MecanumDriveWithJoystick
	JoystickButton *B4;  //DriveBackSideForward
	JoystickButton *B5;  //DriveLeftSideForward
	JoystickButton *B6;  //DriveRighttSideForward

	JoystickButton *B7;  //Unused
	JoystickButton *B8;  //Unused

	JoystickButton *B9;  //DriveToPosition (0,0)

	JoystickButton *B10; //Unused
	JoystickButton *B11; //Unused
	JoystickButton *B12; //Unused

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

	double testx;
	double testy;

	double ninetyDegrees = 90.0;
};

#endif  // OI_H
