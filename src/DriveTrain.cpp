#include "DriveTrain.h"

#include "WPILib.h"

/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive
 * class.
 */
DriveTrain::DriveTrain() {
	stick = new Joystick(kJoystickChannel);
	frontLeftController = new VictorSP(kFrontLeftChannel);
	rearLeftController = new VictorSP(kRearLeftChannel);
	frontRightController = new VictorSP(kFrontRightChannel);
	rearRightController = new VictorSP(kRearRightChannel);
	robotDrive = new RobotDrive(
		frontLeftController, rearLeftController,
		frontRightController, rearRightController
	);
	robotDrive->SetExpiration(0.1);

	// Invert the left side motors
	robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);

	// You may need to change or remove this to match your robot
	robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
}

void DriveTrain::SetSafetyEnabled(bool safety) {
	robotDrive->SetSafetyEnabled(safety);
}

/**
 * Runs the motors with Mecanum drive.
 */
void DriveTrain::update() {
	robotDrive->MecanumDrive_Cartesian(
		stick->GetX(), stick->GetY(),
		stick->GetZ()
	);
}
