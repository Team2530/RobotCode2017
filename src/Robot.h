/*
 * Robot.h
 *
 *  Created on: Jan 16, 2017
 *      Author: Nick
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_


#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "OI.h"
#include "Commands/MecanumDriveWithJoystick.h"
#include "Commands/IntakeOn.h"
#include "Commands/Output.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Dumper.h"
#include "Subsystems/Tracker.h"

#include "WPILib.h" //for automatic balancing
#include "AHRS.h"
#include <math.h>

/*This utilizes the navX MXP to implement an automatic balance feature, which can be used to help avoid the
  the robot tipping over when driving . . .

  The basic principle shown is measurement of the Pitch (rotation about the X axis) and Roll (rotation about
  the Y axis) angles. When these angles exceed the "off balance" threshold and until these angles fall below
  the "on balance" threshold, the drive system is automatically driven in the opposite direction at a
  magnitude proportional to the Pitch or Roll angle.

  Note that this is just a starting a point for automatic balancing, and will likely require a reasonable
  amount of tuning in order to work well with our robot.
  */

static constexpr double kOffBalanceThresholdDegrees = 10.0f; //for automatic balancing
static constexpr double kOnBalanceThresholdDegrees  = 5.0f;

class Robot: public frc::IterativeRobot
{

	bool autoBalanceXMode; //for automatic balancing
	bool autoBalanceYMode;

public:
	static std::shared_ptr<DriveTrain> drivetrain;
	static std::shared_ptr<Dumper> dumper;
	static std::unique_ptr<OI> oi;
	static std::shared_ptr<Intake> intake;
	static std::shared_ptr<Tracker> tracker;
	void RobotInit() override;

	//Start of automatic balancing.

//	try {
//		ahrs = new AHRS(SPI::Port::kMXP);
//    } catch (std::exception& ex ) {
//        std::string err_string = "Error instantiating navX MXP:  ";
//        err_string += ex.what();
//        DriverStation::ReportError(err_string.c_str());
//    }
//    if ( ahrs ) {
//        LiveWindow::GetInstance()->AddSensor("IMU", "Gyro", ahrs);
//    }
//    autoBalanceXMode = false;
//    autoBalanceYMode = false;
//}
//
///*Drive based upon joystick inputs, and automatically control
//  motors if the robot begins tipping.
//  */
//void OperatorControl()
//{
//    robotDrive.SetSafetyEnabled(false);
//    while (IsOperatorControl() && IsEnabled()) {
//
//        double xAxisRate = stick.GetX();
//        double yAxisRate = stick.GetY();
//        double pitchAngleDegrees = ahrs->GetPitch();
//        double rollAngleDegrees = ahrs->GetRoll();
//
//        if ( !autoBalanceXMode &&
//             (fabs(pitchAngleDegrees) >=
//              fabs(kOffBalanceThresholdDegrees))) {
//            autoBalanceXMode = true;
//        }
//        else if ( autoBalanceXMode &&
//                  (fabs(pitchAngleDegrees) <=
//                   fabs(kOnBalanceThresholdDegrees))) {
//            autoBalanceXMode = false;
//        }
//        if ( !autoBalanceYMode &&
//             (fabs(pitchAngleDegrees) >=
//              fabs(kOffBalanceThresholdDegrees))) {
//            autoBalanceYMode = true;
//        }
//        else if ( autoBalanceYMode &&
//                  (fabs(pitchAngleDegrees) <=
//                   fabs(kOnBalanceThresholdDegrees))) {
//            autoBalanceYMode = false;
//        }
//
//        // Control drive system automatically,
//        // driving in reverse direction of pitch/roll angle,
//        // with a magnitude based upon the angle
//
//        if ( autoBalanceXMode ) {
//            double pitchAngleRadians = pitchAngleDegrees * (M_PI / 180.0);
//            xAxisRate = sin(pitchAngleRadians) * -1;
//        }
//        if ( autoBalanceYMode ) {
//            double rollAngleRadians = rollAngleDegrees * (M_PI / 180.0);
//            yAxisRate = sin(rollAngleRadians) * -1;
//        }
//
//        try {
//            // Use the joystick X axis for lateral movement, Y axis for forward movement, and Z axis for rotation.
//            robotDrive.MecanumDrive_Cartesian(xAxisRate, yAxisRate,stick.GetZ());
//        } catch (std::exception& ex ) {
//            std::string err_string = "Drive system error:  ";
//            err_string += ex.what();
//            DriverStation::ReportError(err_string.c_str());
//        }
//        Wait(0.005); // wait 5ms to avoid hogging CPU cycles
//    }
//}

//End of automatic balancing.

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override;
	void DisabledPeriodic() override;

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	// Leftover from example code
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;
};


#endif /* SRC_ROBOT_H_ */
