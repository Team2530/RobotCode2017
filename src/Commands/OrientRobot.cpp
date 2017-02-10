#include "OrientRobot.h"
#include "math.h"
#include "Robot.h"
OrientRobot::OrientRobot(double TargetAngle) {
	double Angle = TargetAngle;

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get()
}

// Called just before this Command runs the first time
void OrientRobot::Initialize() {


}

// Called repeatedly when this Command is scheduled to run
void OrientRobot::Execute() {
	double CurrentAngle = (Robot::oi->GetAHRS()->GetYaw());
	double turningValue = Angle - CurrentAngle;
	turningValue = TurnAngleDetermination(turningValue);
	turningValue = TurningSpeedDetermination(turningValue);
	Robot::drivetrain->DriveWithCoordinates(0.0 ,0.0 ,turningValue);




}

double OrientRobot::TurningSpeedDetermination(double OffsetAngle){
	OffsetAngle /= 180;
	if(OffsetAngle >= 5 || OffsetAngle <= -5){
		OffsetAngle *= 0.25;
	}

	else if(OffsetAngle >= 8 || OffsetAngle <= -3){
		OffsetAngle *= 0.4;
	}
	return OffsetAngle;
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
	double CurrentAngle = (Robot::oi->GetAHRS()->GetYaw());
	if(Angle == CurrentAngle){
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
