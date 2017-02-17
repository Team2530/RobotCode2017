#include "OrientRobot.h"
#include "math.h"
#include "Robot.h"
#include <AHRS.h>


OrientRobot::OrientRobot(double TargetAngle) {
	Angle = TargetAngle;

	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());
}

OrientRobot::OrientRobot(double x, double y) {
	double currentPositionX = Robot::tracker->GetcurrentPositionX();
	double currentPositionY = Robot::tracker->GetcurrentPositionY();

	double TargetAngle = 0; //get real angle

	double deltaxValue = x - currentPositionX;
	double deltayValue = y - currentPositionY;

	if (deltaxValue < 0 && deltayValue > 0){
			TargetAngle = atan ((-deltaxValue) / deltayValue) + 90;
		}
	if (deltaxValue > 0 && deltayValue > 0){
			TargetAngle = atan (deltayValue / deltaxValue);
		}
	if (deltaxValue > 0 && deltayValue < 0){
			TargetAngle = -atan ((-deltayValue) / deltaxValue);
		}
	if (deltaxValue < 0 && deltayValue < 0){
			TargetAngle = -(atan ((-deltaxValue) / (-deltayValue)) + 90);
		}
	*Angle = *TargetAngle;
}



// Called just before this Command runs the first time
void OrientRobot::Initialize() {


}

// Called repeatedly when this Command is scheduled to run
void OrientRobot::Execute() {
	double CurrentAngle = (Robot::oi->GetAHRS()->GetAngle());
	SmartDashboard::PutNumber("CurrentAngle",CurrentAngle);

	double turningValue = *Angle - CurrentAngle;
	turningValue = TurnAngleDetermination(turningValue);
	turningValue = TurningSpeedDetermination(turningValue);
	Robot::drivetrain->DriveWithCoordinates(0.0 ,0.0 ,turningValue);
}

double OrientRobot::TurningSpeedDetermination(double OffsetAngle){

	SmartDashboard::PutNumber("OffsetAngle",OffsetAngle);
	OffsetAngle /= 180.0;
	double MinimumPower;
	double PowerSlope = 0.8;
	double TurningSpeed;
	if (OffsetAngle < 0){
		MinimumPower = -0.2;
	}
	else {
		MinimumPower = 0.2;
	}
	TurningSpeed = (PowerSlope * OffsetAngle) + MinimumPower;

	SmartDashboard::PutNumber("TurningSpeed",TurningSpeed);

	return TurningSpeed;
}


double OrientRobot::TurnAngleDetermination(double OffsetAngle){
	if(OffsetAngle >= 180){
		OffsetAngle = OffsetAngle - 360;
	}
	else if(OffsetAngle <= -180){
		OffsetAngle = OffsetAngle + 360;
	}
	return OffsetAngle;
}

// Make this return true when this Command no longer needs to run execute()
bool OrientRobot::IsFinished() {
	double CurrentAngle = (Robot::oi->GetAHRS()->GetAngle());
	double HowFarOff;
	if (*Angle < CurrentAngle)
		HowFarOff = CurrentAngle - *Angle;
	else
		HowFarOff = *Angle - CurrentAngle;

	if(HowFarOff < 3.0){
		return true;
	}
	else {
		return false;
	}
}


// Called once after isFinished returns true
void OrientRobot::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OrientRobot::Interrupted() {

}
