#ifndef DriveTrain_H
#define DriveTrain_H

#include "WPILib.h"
#include <Commands/Subsystem.h>

#include "AHRS.h" //for automatic balancing

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	// Channels for the wheels
	static constexpr int kFrontLeftChannel = 1;
	static constexpr int kRearLeftChannel = 2;
	static constexpr int kFrontRightChannel = 0;
	static constexpr int kRearRightChannel = 3;

	static constexpr int kJoystickChannel = 4; //Was 0, but a wheel and a joystick cannot run on the same channel

	Spark* frontLeftController;
	VictorSP* rearLeftController;
	Spark* frontRightController;
	VictorSP* rearRightController;


	RobotDrive* robotDrive; // Robot drive system

	AHRS *ahrs;            //for automatic balancing.

public:
	DriveTrain();
	void Drive(Joystick* stick);
	void Stop();
	void InitDefaultCommand();
	void DriveForward();
};

#endif  // DriveTrain_H
