#include "Robot.h"


#include "Commands/AimCameratoTaco.h"
#include "Commands/AimCameratoLift.h"

std::shared_ptr<DriveTrain> Robot::drivetrain;
std::shared_ptr<Dumper> Robot::dumper;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<Tracker> Robot::tracker;
std::shared_ptr<Vision> Robot::vision;
std::shared_ptr<Lifter> Robot::lifter;
std::shared_ptr<CameraServo> Robot::cameraservo;
std::shared_ptr<LED> Robot::led;

StartPosition left = START_LEFT;
StartPosition middle = START_MIDDLE;
StartPosition right = START_RIGHT;
ChosenGear leftGear = GEAR_LEFT;
ChosenGear middleGear = GEAR_MIDDLE;
ChosenGear rightGear = GEAR_RIGHT;

double start0 = 0;
double start90 = 90;
double start_90 = -90;

double Robot::initialX;
double Robot::initialY;
double Robot::hopperX;
double Robot::hopperR;
double Robot::hopperY;
double Robot::boilerX;
double Robot::boilerR;
double Robot::boilerY;
double Robot::gearLifterX;
double Robot::gearLifterY;
double Robot::gearLifterR;
double Robot::positionBaseLineX;
double Robot::positionBaseLineY;
double Robot::positionBaseLineR;

void Robot::RobotInit() {
	// Wait until here to initialize systems that depend on WPILib
	//std::printf("RobotInit start in %s, line %i\n", __FILE__, __LINE__);
	drivetrain = std::make_shared<DriveTrain>();
	dumper = std::make_shared<Dumper>();
	intake = std::make_shared<Intake>();
	tracker = std::make_shared<Tracker>();
	led = std::make_shared<LED>();


	oi = std::make_unique<OI>();

	vision = std::make_shared<Vision>();
    lifter = std::make_shared<Lifter>();
    cameraservo = std::make_shared<CameraServo>();

	chooserDo.AddDefault("Cross BaseLine", new CrossBaseLine()); //starting action
	chooserDo.AddObject("Do Nothing", new DoNothing());//^^
	chooserDo.AddObject("Deliver Gear", new DeliverGear());
	SmartDashboard::PutData("Autonomous modes", &chooserDo);

	chooserGear.AddObject("Left Gear", &leftGear);//choose which gear to go to
	chooserGear.AddDefault("Middle Gear", &middleGear);//^^
	chooserGear.AddObject("Right Gear", &rightGear);//^^




	chooserPos.AddObject("Left", &left); //starting position
	chooserPos.AddDefault("Middle", &middle);//^^
	chooserPos.AddObject("Right", &right);//^^

	chooserAngle.AddDefault("Start facing forward", &start0);
	chooserAngle.AddObject("Start with taco forward", &start_90);
	SmartDashboard::PutData("Starting orientation", &chooserAngle);
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
	oi->GetAHRS()->Reset();
	StartPosition* autonomousPos = &middle; // chooserPos.GetSelected();
	ChosenGear* targetGear = &middleGear; // chooserGear.GetSelected();
	frc::DriverStation::Alliance team = frc::DriverStation::GetInstance().GetAlliance();
	Command* autonomousDo = chooserDo.GetSelected();
	double* angle = chooserAngle.GetSelected();
	if (angle != nullptr) {
		oi->GetAHRS()->SetAngleAdjustment(*angle);
	}
	Robot::initialY = StartingPlaceY;
	Robot::hopperY = hopperPositionY;
	Robot::boilerY = boilerPositionY;
	if (team == frc::DriverStation::Alliance::kBlue) {
		Robot::boilerX = blueBoilerPositionX;
		Robot::boilerR = blueBoilerPositionR;
		Robot::hopperX = blueHopperPositionX;
		Robot::hopperR = blueHopperPositionR;

		switch (*autonomousPos) {
		case START_LEFT:
			Robot::initialX = startingBlueLeftX;
			break;
		case START_MIDDLE:
			Robot::initialX = startingBlueMiddleX;
			break;
		case START_RIGHT:
			Robot::initialX = startingBlueRightX;
			break;
		}
	} else {
		Robot::boilerX = redBoilerPositionX;
		Robot::boilerR = redBoilerPositionR;
		Robot::hopperX = redHopperPositionX;
		Robot::hopperR = redHopperPositionR;
		switch (*autonomousPos) {
		case START_LEFT:
			Robot::initialX = startingRedLeftX;
			Robot::positionBaseLineX = initialX;
			Robot::positionBaseLineY = initialY + 93.5;
			Robot::positionBaseLineR = 0;
			break;
		case START_RIGHT:
			Robot::initialX = startingRedRightX;
			Robot::positionBaseLineX =  initialX;
			Robot::positionBaseLineY =  initialY + 93.5;
			Robot::positionBaseLineR =  0;
			break;
		case START_MIDDLE:
			Robot::initialX = startingRedMiddleX;
			Robot::positionBaseLineX = middleBaseLineX;
			Robot::positionBaseLineY = middleBaseLineY;
			Robot::positionBaseLineR = middleBaseLineR;
			break;
		}
	}
	switch (*targetGear){
	case GEAR_LEFT:
			Robot::gearLifterX = leftGearPlaceX;
			Robot::gearLifterY = leftGearPlaceY;
			Robot::gearLifterR = leftGearPlaceR;
			break;
	case GEAR_MIDDLE:
			Robot::gearLifterX = middleGearPlaceX;
			Robot::gearLifterY = middleGearPlaceY;
			Robot::gearLifterR = middleGearPlaceR;
			break;
	case GEAR_RIGHT:
			Robot::gearLifterX = rightGearPlaceX;
			Robot::gearLifterY = rightGearPlaceY;
			Robot::gearLifterR = rightGearPlaceR;
			break;
	}
	tracker->StartTracking();

	autonomousDo->Start();
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
	//??autonomous->End();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	frc::LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)
