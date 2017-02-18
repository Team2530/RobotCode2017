#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>

//#include <Subsystems/AHRS.h>
#include <AHRS.h>


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
	JoystickButton *B9;  //Dump
	JoystickButton *B10; //ResetDump
	JoystickButton *B11; //MecanumDriveFieldOriented

	JoystickButton *B12; //Unused

	AHRS* ahrs;			 //navX MXP

	double testx;
	double testy;

	double ninetyDegrees = 90.0;
	double ninetyDegrees = 90.0;
};

#endif  // OI_H
