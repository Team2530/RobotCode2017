#ifndef DriveTrain_H
#define DriveTrain_H

#include "WPILib.h"
#include <Commands/Subsystem.h>
#include "Tracker.h"

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	// Channels for the wheels
	static constexpr int kFrontLeftChannel = 1;
	static constexpr int kRearLeftChannel = 2;
	static constexpr int kFrontRightChannel = 0;
	static constexpr int kRearRightChannel = 3;

	static constexpr int kJoystickChannel = 0;

	VictorSP* frontLeftController;
	VictorSP* rearLeftController;
	VictorSP* frontRightController;
	VictorSP* rearRightController;

	// Robot drive system
	frc::RobotDrive* robotDrive;
public:
	DriveTrain();
	void Drive(Joystick* stick);
	void Track(Tracker* tracker);
	void Stop();
	void InitDefaultCommand();
	void DriveForward();

	void DriveWithCoordinates(double x, double y, double z, double Angle);

	void DriveLeft();
	void DriveLeftSideForward(Joystick* stick);
	void DriveRightSideForward(Joystick* stick);
	void DriveBackSideForward(Joystick* stick);
//	void DrivePastBaseLine();

};

#endif  // DriveTrain_H
