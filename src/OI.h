#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <XboxController.h>
#include "WPILib.h"
#include <Buttons/JoystickButton.h>

//#include <Subsystems/AHRS.h>
#include <AHRS.h>
#include "Subsystems/ControllerConstants.h"


class OI {
public:
	OI();
	Joystick* GetJoystick();
	AHRS* GetAHRS();
private:
	Joystick* joy;
	JoystickButton *B1;  //LED Control

	JoystickButton *B2;  //DriveToPosition Test

	JoystickButton *B3;  //DriveForward
	JoystickButton *B4;  //DriveLeftSideForward

	JoystickButton *B5;  //Unused

	JoystickButton *B6;  //OrientRobot90
	JoystickButton *B7;  //IntakeOn
	JoystickButton *B8;  //IntakeInvert
	JoystickButton *B9;  //Unused
	JoystickButton *B10; //ResetDump
	JoystickButton *B11; //MecanumDriveFieldOriented

	JoystickButton *B12; //Unused

	XboxController *Xbox;
	JoystickButton *A; // intake on
	JoystickButton *B; // intake off
	JoystickButton *Y; // intake invert
	JoystickButton *X; // dump/reset
	JoystickButton *RB; // control fast lift
	JoystickButton *LB; // control slow lift
	JoystickButton *Back; // camera face forward
	JoystickButton *Start; // camera face for taco

	AHRS* ahrs;			 //navX MXP

	double testx;
	double testy;

	double ninetyDegrees = 90.0;
};

#endif  // OI_H
