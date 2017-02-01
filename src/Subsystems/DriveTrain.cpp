#include "DriveTrain.h"
#include "../RobotMap.h"
#include "ControllerConstants.h"

#include "../Commands/MecanumDriveWithJoystick.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrainSubsystem") {
	frontLeftController = new Spark(kFrontLeftChannel);
	rearLeftController = new VictorSP(kRearLeftChannel);
	frontRightController = new Spark(kFrontRightChannel);
	rearRightController = new VictorSP(kRearRightChannel);

	frontEncoder = new Encoder (ControllerConstants::DIOPort::kDIO2, ControllerConstants::DIOPort::kDIO3, true, CounterBase:: k4X); //check ports
	sideEncoder = new Encoder (ControllerConstants::DIOPort::kDIO0, ControllerConstants::DIOPort::kDIO1, true, CounterBase:: k4X);
	frontEncoder->SetDistancePerPulse(kFronDistancePerPulse); //check circumference/(pulses per revolution)
	sideEncoder->SetDistancePerPulse(kSideDistancePerPulse);

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

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new MecanumDriveWithJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::Drive(Joystick* stick) {
	double scale = 0.6-0.4*stick->GetThrottle();
	robotDrive->MecanumDrive_Cartesian(
		scale*stick->GetX(), scale*stick->GetY(),
		scale*stick->GetZ()
	);
}

void DriveTrain::Stop() {
	// TODO: is there a stop command for robot drive?
	robotDrive->MecanumDrive_Cartesian(0,0,0);
}
void DriveTrain::DriveForward() {
	// TODO: is there a stop command for robot drive?
	robotDrive->MecanumDrive_Cartesian(0,-0.5,0);
}


