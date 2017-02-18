/*
 * Robot.h
 *
 *  Created on: Jan 16, 2017
 *      Author: Nick
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_


#include <memory>
#include "WPILib.h"
#include "DriverStation.h"

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "OI.h"

#include "Commands/MecanumDriveWithJoystick.h"
#include "Commands/IntakeOn.h"
#include "Commands/Dump.h"
#include "Commands/IntakeInvert.h"
#include "Commands/Output.h"
#include "Commands/CrossBaseLine.h"
#include "Commands/DoNothing.h"
#include "CommandGroups/DeliverGear.h"

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Dumper.h"
#include "Subsystems/Tracker.h"
#include "Subsystems/Vision.h"

#include "StartPositions.h"


class Robot: public frc::IterativeRobot {
public:

	static std::shared_ptr<DriveTrain> drivetrain;
	static std::shared_ptr<Dumper> dumper;
	static std::unique_ptr<OI> oi;
	static std::shared_ptr<Intake> intake;
	static std::shared_ptr<Tracker> tracker;
	static std::shared_ptr<Vision> vision;

	// Initial robot position for Tracker based on StartPosition chooser
	static double initialX;
	static double initialY;
	static double hopperX;
	static double hopperR;
	static double hopperY;
	static double boilerX;
	static double boilerR;
	static double boilerY;
	static double gearLifterX;
	static double gearLifterY;
	static double gearLifterR;

	void RobotInit() override;

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

	std::unique_ptr<frc::Command> autonomous;
	frc::SendableChooser<frc::Command*> chooserDo;
	frc::SendableChooser<StartPosition*> chooserPos;
	frc::SendableChooser<ChosenGear*> chooserGear;
};


#endif /* SRC_ROBOT_H_ */
