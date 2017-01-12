#include "WPILib.h"

#ifndef SRC_DRIVE_TRAIN_H_
#define SRC_DRIVE_TRAIN_H_

/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive
 * class.
 */
class DriveTrain {
public:
	DriveTrain();
	void update();
	void SetSafetyEnabled(bool safety);

private:
	// Channels for the wheels
	static constexpr int kFrontLeftChannel = 2;
	static constexpr int kRearLeftChannel = 3;
	static constexpr int kFrontRightChannel = 1;
	static constexpr int kRearRightChannel = 0;

	static constexpr int kJoystickChannel = 0;

	VictorSP* frontLeftController;
	VictorSP* rearLeftController;
	VictorSP* frontRightController;
	VictorSP* rearRightController;

	// Robot drive system
	RobotDrive* robotDrive;
	// Only joystick
	Joystick* stick;
};

#endif // SRC_DRIVE_TRAIN_H_
