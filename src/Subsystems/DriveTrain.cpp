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

	// Invert the left side motors
	robotDrive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);

	// You may need to change or remove this to match your robot
	robotDrive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new MecanumDriveFieldOriented());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::Drive(Joystick* stick) {
    if (stick) {
	    double scale = 0.6-0.4*stick->GetThrottle();
	    DriveWithCoordinates(
	  	      scale*stick->GetX(), scale*stick->GetY(),
	  	      scale*stick->GetZ(), 0
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
	robotDrive->MecanumDrive_Cartesian(deadband(x), deadband(y), deadband(z), Angle);
}


void DriveTrain::Stop() {

	robotDrive->MecanumDrive_Cartesian(0,0,0);
}
void DriveTrain::DriveForward() {

	robotDrive->MecanumDrive_Cartesian(0,-0.5,0);
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
