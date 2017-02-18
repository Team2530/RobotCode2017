 #include "DriveTrain.h"
#include "../RobotMap.h"
#include "ControllerConstants.h"

#include "../Commands/MecanumDriveWithJoystick.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrainSubsystem") {
	frontLeftController = new VictorSP(kFrontLeftChannel);
	rearLeftController = new VictorSP(kRearLeftChannel);
	frontRightController = new VictorSP(kFrontRightChannel);
	rearRightController = new VictorSP(kRearRightChannel);



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
	//std::printf("Drive (stick=%p) in %s, line %i\n", stick, __FILE__, __LINE__);
	  if (stick) {
	    double scale = 0.6-0.4*stick->GetThrottle();
	    robotDrive->MecanumDrive_Cartesian(
	      scale*stick->GetX(), scale*stick->GetY(),
	      scale*stick->GetZ()
	    );
	  }
}

void DriveTrain::DriveWithCoordinates(double x, double y, double z, double Angle){
	robotDrive->MecanumDrive_Cartesian(x, y, z, Angle);
}

void DriveTrain::Stop() {

	robotDrive->MecanumDrive_Cartesian(0,0,0);
}
void DriveTrain::DriveForward() {

	robotDrive->MecanumDrive_Cartesian(0,-0.5,0);
}

void DriveTrain::DriveLeftSideForward(Joystick* stick) {
	double scale = 0.6-0.4*stick->GetThrottle();
	robotDrive->MecanumDrive_Cartesian(
		scale*stick->GetY(), -scale*stick->GetX(),
		scale*stick->GetZ()
	);
}
void DriveTrain::DrivePastBaseLine(){


}

void DriveTrain::Track(Tracker* tracker) {
	robotDrive->MecanumDrive_Cartesian(
		tracker->GetPIDBackward(),
		tracker->GetPIDRight(),
		tracker->GetPIDRotation()
	);
}
