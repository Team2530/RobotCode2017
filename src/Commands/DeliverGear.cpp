/*
 * DeliverGear.cpp
 *
 *  Created on: Feb 1, 2017
 *      Author: Shadotiz
 */
//For auto mode, incorporates gyro and tracker, but not vision yet. Builds successfully.
#include <cmath>

#include <AnalogGyro.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <RobotDrive.h>

#include "../Commands/GetFieldPosition.h"
#include "../Subsystems/Tracker.h"
#include "../RobotMap.h"
#include "AHRS.h"

/**
 * This is a sample program to demonstrate how to use a gyro sensor to make a robot drive
 * straight. This program uses a joystick to drive forwards and backwards while the gyro
 * is used for direction keeping.
 */
class Robot: public frc::IterativeRobot {
public:
	void RobotInit() override {
		gyro.SetSensitivity(kVoltsPerDegreePerSecond);
	}

	/**
	 * The motor speed is set from the joystick while the RobotDrive turning
	 * value is assigned from the error between the setpoint and the gyro angle.
	 */
	void TeleopPeriodic() override {
		double turningValue = (kAngleSetpoint - gyro.GetAngle()) * kP;
		// Invert the direction of the turn if we are going backwards
		turningValue = std::copysign(turningValue, joystick.GetY());
		myRobot.Drive(joystick.GetY(), turningValue);
	}

private:
	static constexpr double kAngleSetpoint = 0.0;
	static constexpr double kP = 0.005;  // Proportional turning constant

	// Gyro calibration constant, may need to be adjusted
	// Gyro value of 360 is set to correspond to one full revolution
	static constexpr double kVoltsPerDegreePerSecond = 0.0128;

	static constexpr int kLeftMotorPort = 0;
	static constexpr int kRightMotorPort = 1;
	static constexpr int kGyroPort = 0;
	static constexpr int kJoystickPort = 0;

	frc::RobotDrive myRobot { kLeftMotorPort, kRightMotorPort };
	frc::AnalogGyro gyro { kGyroPort };
	frc::Joystick joystick { kJoystickPort };
};

Tracker::Tracker() : Subsystem("TrackerSubsystem") {

}

void Tracker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::GetPosition(){
	double xValue;
	double yValue;
	Tracker->UpdateDisplacement(float GetRawAccelX, float GetRawAccelY, int 50, bool true)
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

