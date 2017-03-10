 #include "DriveTrain.h"
#include "../RobotMap.h"
#include "ControllerConstants.h"

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
	    DriveWithCoordinates(
	  	      stick->GetX(), stick->GetY(),
	  	      stick->GetZ(), orientation, stick->GetThrottle()
	    );
    }
}

void DriveTrain::DriveLeft() {
	robotDrive->MecanumDrive_Cartesian(-0.5,0,0);

}

void DriveTrain::DriveLeftSideForward(Joystick* stick) {
    if (stick) {

	    DriveWithCoordinates(
	  	     stick->GetX(), stick->GetY(),
	  	      stick->GetZ(), 90, stick->GetThrottle()
	    );
    }
}



void DriveTrain::DriveRightSideForward(Joystick* stick) {
    if (stick) {

	    DriveWithCoordinates(
	  	      stick->GetX(), stick->GetY(),
	  	      stick->GetZ(), -90, stick->GetThrottle()
	    );
    }
}

void DriveTrain::DriveBackSideForward(Joystick* stick) {
    if (stick) {

	    DriveWithCoordinates(
	  	      stick->GetX(), stick->GetY(),
	  	     stick->GetZ(), 180, stick->GetThrottle()
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
double GetThrottleMultiplier (double CurrentThrottle) {
	const double MinThrottle = 0.3 ;
	return  -((1-MinThrottle)/2)*CurrentThrottle+((1-MinThrottle)/2)+MinThrottle;
}
double GetScaledPower (double unscaledPower, double ThrottleMultiplier, double db, double MinPower) {
	double absPower = std::fabs(unscaledPower);
	if (absPower < db) return 0;
	double scaledPower = (ThrottleMultiplier-MinPower)*absPower+MinPower;
    double finalPower = std::copysign(scaledPower, unscaledPower);
    return finalPower;
}
void DriveTrain::DriveWithCoordinates(double x, double y, double z, double Angle, double Throttle) {
	const double MinPower = 0.1;

	double tm = GetThrottleMultiplier (Throttle);

	x=GetScaledPower(x,tm,db,MinPower);
	y=GetScaledPower(y,tm,db,MinPower);
	z=GetScaledPower(z,tm,db,0.05);
	robotDrive->MecanumDrive_Cartesian(x,y,z,Angle);
}

void DriveTrain::DirectDrive(double x, double y, double z) {
	const double db = 0.001;
	const double MinPower = 0.1;
	x=GetScaledPower(x,1.0,db,MinPower*2);
	y=GetScaledPower(y,1.0,db,MinPower);
	z=GetScaledPower(z,1.0,db,0.05);
	robotDrive->MecanumDrive_Cartesian(x, y, z);
}


void DriveTrain::Stop() {
	robotDrive->MecanumDrive_Cartesian(0,0,0);
}



