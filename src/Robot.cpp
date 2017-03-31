#include "Robot.h"

#include "Commands/MecanumDriveWithJoystick.h"
#include "Commands/MecanumDriveFieldOriented.h"
#include "Commands/IntakeOn.h"
#include "Commands/Dump.h"
#include "Commands/IntakeInvert.h"
#include "Commands/DoNothing.h"
#include "Commands/DeliverGear.h"
#include "Commands/DeliverGearDumpHopper.h"
#include "Commands/DriveToFieldPosition.h"
#include "Commands/PerimeterMovement.h"
#include "Commands/DumpThenGear.h"
#include "Commands/DeliverGearDumpHopper.h"
#include "FieldPositions/GearFieldPosition.h"

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
std::shared_ptr<AutoDrive> Robot::autodrive;

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
RobotChoice Robot::thisRobot = ZOMBERDINCK;

RobotChoice max = MIRACLE_MAX;
RobotChoice zomber = ZOMBERDINCK;

void Robot::RobotInit() {
	// Wait until here to initialize systems that depend on WPILib
	//std::printf("RobotInit start in %s, line %i\n", __FILE__, __LINE__);
	drivetrain = std::make_shared<DriveTrain>();
	dumper = std::make_shared<Dumper>();
	intake = std::make_shared<Intake>();
	tracker = std::make_shared<Tracker>();
	led = std::make_shared<LED>();
    autodrive = std::make_shared<AutoDrive>();

	vision = std::make_shared<Vision>();
    lifter = std::make_shared<Lifter>();

    cameraservo = std::make_shared<CameraServo>();

	oi = std::make_unique<OI>();

	chooserDo.AddDefault("Cross BaseLine", new DriveToFieldPosition(new CrossBaseLineFieldPosition(), 0.5)); //starting action
	/*
	chooserDo.AddObject("Do Nothing", new DoNothing());//^^
	chooserDo.AddObject("Deliver Gear", new DeliverGear());
	chooserDo.AddObject("Perimeter Movement Test", new PerimeterMovement());
	chooserDo.AddObject("Deliver Gear Then Dump Hopper", new DeliverGearDumpHopper());//Subject to change
	chooserDo.AddObject("Deliver Fuel then Gear", new DumpThenGear());
	chooserDo.AddObject("Drive to gear ONLY", new DriveToFieldPosition(new GearFieldPosition()));
	/*/
	chooserDo.AddObject("Deliver Gear (df)", new DeliverGear(DG_default));
	chooserDo.AddObject("Deliver Gear: 4sec initial", new DeliverGear(DG_4sec));
	chooserDo.AddObject("Deliver Gear: no second vision step", new DeliverGear(DG_no2nd));
	chooserDo.AddObject("Deliver Gear: 4sec init, no second visn", new DeliverGear(DG_4sec_no2nd));
	chooserDo.AddObject("Deliver Gear: no first vision step", new DeliverGear(DG_no1st));
	chooserDo.AddObject("Deliver Gear: 4sec init, no first visn", new DeliverGear(DG_4sec_no1st));
	//*/
	SmartDashboard::PutData("Autonomous modes", &chooserDo);

	chooserGear.AddObject("Left Gear", &leftGear);//choose which gear to go to
	chooserGear.AddDefault("Middle Gear", &middleGear);//^^
	chooserGear.AddObject("Right Gear", &rightGear);//^^
	SmartDashboard::PutData("Choose Gear", &chooserGear);

	chooserPos.AddObject("Left", &left); //starting position
	chooserPos.AddDefault("Middle", &middle);//^^
	chooserPos.AddObject("Right", &right);//^^
	SmartDashboard::PutData("Start Position", &chooserPos);

	chooserAngle.AddDefault("Start facing forward", &start0);
	chooserAngle.AddObject("Start with taco forward", &start90);
	SmartDashboard::PutData("Starting orientation", &chooserAngle);

	chooserBot.AddDefault("Miracle Max", &max);
	chooserBot.AddObject("Zomberdinck", &zomber);
	SmartDashboard::PutData("This Robot", &chooserBot);
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

	if (oi->GetAHRS() != nullptr)
		oi->GetAHRS()->Reset();
	StartPosition* autonomousPos = chooserPos.GetSelected();
	ChosenGear* targetGear = chooserGear.GetSelected();
	frc::DriverStation::Alliance team = frc::DriverStation::GetInstance().GetAlliance();
	Command* autonomousDo = chooserDo.GetSelected();
	double* angle = chooserAngle.GetSelected();

	//if(chooserDo.GetSelected() == DumpThenGear()){
	//	angle = -90;
	//}
	double initialAngle = 0;
	if (angle != nullptr) initialAngle = *angle;

	if (chooserBot.GetSelected() != nullptr)
		thisRobot = *chooserBot.GetSelected();

	drivetrain->SetRobot(thisRobot);

	Robot::initialY = StartingPlaceY;
	Robot::boilerY = boilerPositionY;
	if (team == frc::DriverStation::Alliance::kBlue) {
		Robot::boilerX = blueBoilerPositionX;
		Robot::boilerR = blueBoilerPositionR;
		//Robot::hopperX = blueHopperPositionX;
		//Robot::hopperR = blueHopperPositionR;

		switch (*autonomousPos) {
		case START_LEFT:
			Robot::initialX = startingBlueLeftX;
			Robot::hopperX = blueHopperPositionLX;
			Robot::hopperY = blueHopperPositionLY;
			Robot::hopperR = blueHopperPositionLR;
			break;
		case START_MIDDLE:
			Robot::initialX = startingBlueMiddleX;
			Robot::hopperX = blueHopperPositionLX;
			Robot::hopperY = blueHopperPositionLY;
			Robot::hopperR = blueHopperPositionLR;
			break;
		case START_RIGHT:
			Robot::initialX = startingBlueRightX;
			Robot::hopperX = blueHopperPositionRX;
			Robot::hopperY = blueHopperPositionRY;
			Robot::hopperR = blueHopperPositionRR;
			break;
		}
	} else {
		Robot::boilerX = redBoilerPositionX;
		Robot::boilerR = redBoilerPositionR;
		//Robot::hopperX = redHopperPositionX;
		//Robot::hopperR = redHopperPositionR;
		switch (*autonomousPos) {
		case START_LEFT:
			Robot::initialX = startingRedLeftX;
			Robot::positionBaseLineX = initialX;
			Robot::positionBaseLineY = initialY + 93.5;
			Robot::positionBaseLineR = 0;
			Robot::hopperX = redHopperPositionLX;
			Robot::hopperY = redHopperPositionLY;
			Robot::hopperR = redHopperPositionLR;
			break;
		case START_RIGHT:
			Robot::initialX = startingRedRightX;
			Robot::positionBaseLineX =  initialX;
			Robot::positionBaseLineY =  initialY + 93.5;
			Robot::positionBaseLineR =  0;
			Robot::hopperX = redHopperPositionRX;
			Robot::hopperY = redHopperPositionRY;
			Robot::hopperR = redHopperPositionRR;
			break;
		case START_MIDDLE:
			Robot::initialX = startingRedMiddleX;
			Robot::positionBaseLineX = middleBaseLineX;
			Robot::positionBaseLineY = middleBaseLineY;
			Robot::positionBaseLineR = middleBaseLineR;
			Robot::hopperX = redHopperPositionLX;
			Robot::hopperY = redHopperPositionLY;
			Robot::hopperR = redHopperPositionLR;
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
	std::printf("Initial X: %f\nInitial Y: %f\nInitial R: %f\n", Robot::initialX, Robot::initialY, initialAngle);
	std::printf("Gear X: %f\nGear Y: %f\nGear R: %f\n", Robot::gearLifterX, Robot::gearLifterY, Robot::gearLifterR);
	tracker->StartTracking(Robot::initialX, Robot::initialY, initialAngle);

	autonomousDo->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	if (chooserBot.GetSelected() != nullptr)
		thisRobot = *chooserBot.GetSelected();

	SmartDashboard::PutNumber("This  Robot", static_cast<char>(thisRobot));
	drivetrain->SetRobot(thisRobot);
	Command* dfault = new MecanumDriveFieldOriented();
	dfault->Start();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	frc::LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)
