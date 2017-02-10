#include "Robot.h"
#include "WPILib.h"


#include "Commands/TrackerInit.h"

std::shared_ptr<DriveTrain> Robot::drivetrain;
std::shared_ptr<Dumper> Robot::dumper;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<Tracker> Robot::tracker;

SendableChooser<Command*> chooserDo;
SendableChooser<Command*> chooserPos;

void Robot::RobotInit() {
	// Wait until here to initialize systems that depend on WPILib
	drivetrain = std::make_shared<DriveTrain>();
	dumper = std::make_shared<Dumper>();
	oi = std::make_unique<OI>();
	intake = std::make_shared<Intake>();
	// Get the USB camera from CameraServer
	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture("USB Camera 0", 0);
	// Set the resolution
	camera.SetResolution(320, 240);
	camera.SetExposureManual(20);
	camera.SetBrightness(100);
	tracker = std::make_shared<Tracker>();

	/* TODO:
	chooserDo.AddDefault("Do Nothing", new DoNothing()); //starting action
	chooserDo.AddObject("Cross BaseLine", new CrossBaseLine());//^^
	chooserDo.AddObject("Deliver Gear", new DeliverGear(););//^^
	*/

	chooserPos.AddObject("Blue Left", new TrackerInit(START_LEFT, BLUE_TEAM)); //starting position
	chooserPos.AddObject("Blue Middle", new TrackerInit(START_MIDDLE,BLUE_TEAM));//^^
	chooserPos.AddObject("Blue Right", new TrackerInit(START_RIGHT, BLUE_TEAM));//^^


	chooserPos.AddObject("Red Left", new TrackerInit(START_LEFT, RED_TEAM)); //starting position
	chooserPos.AddObject("Red Middle", new TrackerInit(START_MIDDLE,RED_TEAM));//^^
	chooserPos.AddObject("Red Right", new TrackerInit(START_RIGHT, RED_TEAM));//^^




}

/**
 * This function is called once each time the robot enters Disabled mode.
 * You can use it to reset any subsystem information you want to clear when
 * the robot is disabled.
 */
void Robot::DisabledInit() {

}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

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
void Robot::AutonomousInit() {
	/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
	if (autoSelected == "My Auto") {
		autonomousCommand.reset(new MyAutoCommand());
	}
	else {
		autonomousCommand.reset(new ExampleCommand());
	} */
	// TODO: add chooserDo here too!
	Command* autonomous = chooserPos.GetSelected();
	autonomous->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	/*if (autonomousCommand != nullptr) {
		autonomousCommand->Cancel();
	}*/
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	frc::LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)
