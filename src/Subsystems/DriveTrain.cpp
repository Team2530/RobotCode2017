 #include "DriveTrain.h"
#include "../RobotMap.h"
#include "ControllerConstants.h"

#include "../Commands/MecanumDriveWithJoystick.h"
#include "../Commands/MecanumDriveFieldOriented.h"

#include <math.h>

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

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new MecanumDriveFieldOriented());
}

void DriveTrain::SetRobot(RobotChoice thisRobot) {

	if (thisRobot == MIRACLE_MAX) {

		// Invert motors for max
		robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);

	} else if (thisRobot == ZOMBERDINCK) {

		// Invert the left side motors for zomberdinck
		robotDrive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	}
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::Drive(Joystick* stick, Orientation orientation) {
    if (stick) {
	    double scale = 0.6-0.4*stick->GetThrottle();
	    DriveWithCoordinates(
	  	      scale*stick->GetX(), scale*stick->GetY(),
	  	      scale*stick->GetZ(), orientation
	    );
    }
}

void DriveTrain::DriveLeft() {
	robotDrive->MecanumDrive_Cartesian(-0.5,0,0);

}

void DriveTrain::DriveLeftSideForward(Joystick* stick) {
    if (stick) {
	    double scale = 0.6-0.4*stick->GetThrottle();
	    DriveWithCoordinates(
	  	      scale*stick->GetX(), scale*stick->GetY(),
	  	      scale*stick->GetZ(), 90
	    );
    }
}



void DriveTrain::DriveRightSideForward(Joystick* stick) {
    if (stick) {
	    double scale = 0.6-0.4*stick->GetThrottle();
	    DriveWithCoordinates(
	  	      scale*stick->GetX(), scale*stick->GetY(),
	  	      scale*stick->GetZ(), -90
	    );
    }
}

void DriveTrain::DriveBackSideForward(Joystick* stick) {
    if (stick) {
	    double scale = 0.6-0.4*stick->GetThrottle();
	    DriveWithCoordinates(
	  	      scale*stick->GetX(), scale*stick->GetY(),
	  	      scale*stick->GetZ(), 180
	    );
    }
}

const double db = 0.1;

double deadband(double value) {
	if (value > 0) {
		if (value > db) return (value - db)/(1-db);
	} else {
		if (value < -db) return (value + db)/(1-db);
	}
	return 0;
}

void DriveTrain::DriveWithCoordinates(double x, double y, double z, double Angle) {
	z = z*std::abs(z);
	DirectDrive(deadband(x), deadband(y), deadband(z), Angle);
}

void DriveTrain::DirectDrive(double x, double y, double z, double Angle) {
	robotDrive->MecanumDrive_Cartesian(x, y, z, Angle);
}


void DriveTrain::Stop() {

	robotDrive->MecanumDrive_Cartesian(0,0,0);
}
void DriveTrain::DriveForward() {

	robotDrive->MecanumDrive_Cartesian(0,-0.5,0);
}

//void DriveTrain::DrivePastBaseLine(){


//}
