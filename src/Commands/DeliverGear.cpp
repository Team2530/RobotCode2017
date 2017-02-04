/*
 * DeliverGear.cpp
 *
 *  Created on: Feb 1, 2017
 *      Author: Shadotiz
 */
/*For auto mode, incorporates gyro and tracker, not yet vision, using iterative instead of command based (probably not
  accurately). Does not compile successfully due to tracker part.
  */

#include <cmath>

#include <thread>

#include <AnalogGyro.h>     //for gyro
#include <IterativeRobot.h>
#include <Joystick.h>
#include <RobotDrive.h>

#include "../Commands/GetFieldPosition.h" //for tracker
#include "../Subsystems/Tracker.h"
#include "../RobotMap.h"
#include "AHRS.h"

#include <CameraServer.h> //for vision

//This uses a gyro sensor to make the robot drive straight and for direction keeping.

//class Robot: public frc::IterativeRobot {
//public:
//	void RobotInit() override {
//		gyro.SetSensitivity(kVoltsPerDegreePerSecond);
//	}
//
//	/*The motor speed is set from the joystick while the RobotDrive turning
//	  value is assigned from the error between the setpoint and the gyro angle.
//	  */

//	void TeleopPeriodic() override {
//		double turningValue = (kAngleSetpoint - gyro.GetAngle()) * kP;
//		// Invert the direction of the turn if we are going backwards
//		turningValue = std::copysign(turningValue, joystick.GetY());
//		myRobot.Drive(joystick.GetY(), turningValue);
//	}
//
//private:
//	static constexpr double kAngleSetpoint = 0.0;
//	static constexpr double kP = 0.005;  // Proportional turning constant
//
//	// Gyro calibration constant, may need to be adjusted
//	// Gyro value of 360 is set to correspond to one full revolution
//	static constexpr double kVoltsPerDegreePerSecond = 0.0128;
//
//	static constexpr int kLeftMotorPort = 0;
//	static constexpr int kRightMotorPort = 1;
//	static constexpr int kGyroPort = 0;
//	static constexpr int kJoystickPort = 0;
//
//	frc::RobotDrive myRobot { kLeftMotorPort, kRightMotorPort };
//	frc::AnalogGyro gyro { kGyroPort };
//	frc::Joystick joystick { kJoystickPort };
//};

//Tracker::Tracker() : Subsystem("TrackerSubsystem") {
//
//}

void Tracker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::GetPosition(){
	double xValue;
	double yValue;
	Tracker->UpdateDisplacement(float GetRawAccelX, float GetRawAccelY, int 50, bool true);
}
ExampleCommand::ExampleCommand() {

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

}

// Called just before this Command runs the first time

void ExampleCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run

void ExampleCommand::Execute() {

}

// Make this return true when this Command no longer needs to run execute()

bool ExampleCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true

void ExampleCommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run

void ExampleCommand::Interrupted() {

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
