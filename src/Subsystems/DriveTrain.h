#ifndef DriveTrain_H
#define DriveTrain_H

#include "WPILib.h"
#include "StartPositions.h"

using namespace frc;

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
	void InitDefaultCommand();
	void SetRobot(RobotChoice thisRobot);
	bool Drive(Joystick* stick, Orientation orientation = FRONT_FORWARD, double headinglock=0);
	void DriveLeft();
	void DriveLeftSideForward(Joystick* stick);
	void DriveRightSideForward(Joystick* stick);
	void DriveBackSideForward(Joystick* stick);

	bool DriveWithCoordinates(double x, double y, double z, double Angle, double Throttle, double headinglock=0);
	// Robot oriented: increase left/right authority
	void DirectDrive(double x, double y, double z, double angle);

	void Stop();
};

#endif  // DriveTrain_H
