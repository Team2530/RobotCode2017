#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <XboxController.h>
#include "WPILib.h"
#include <Buttons/JoystickButton.h>
#include "Subsystems/ControllerConstants.h"
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
	JoystickButton *B3;  //MecanumDriveFieldOriented
	JoystickButton *B4;  //DriveLeftSideForward
	JoystickButton *B5;  //DriveLeft
	JoystickButton *B6;  //DriveBackSideForward

	JoystickButton *B7;  //Unused
	JoystickButton *B8;  //Unused
	JoystickButton *B9;  //Unused
	JoystickButton *B10; //Unused

	JoystickButton *B11; //DriveForward
	JoystickButton *B12; //OrientRobotNinetyDegrees

	XboxController *Xbox;
	JoystickButton *A; // intake on
	JoystickButton *B; // LED Toggle
	JoystickButton *Y; // intake invert
	JoystickButton *X; // intake off
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
