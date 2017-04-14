#include "Robot.h"
#include <Commands/AimCameratoFrontTaco.h>

AimCameratoFrontTaco::AimCameratoFrontTaco() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::cameraservo.get());
}

// Called just before this Command runs the first time
void AimCameratoFrontTaco::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AimCameratoFrontTaco::Execute() {
	Robot::cameraservo->AimFrontTaco();
}

// Make this return true when this Command no longer needs to run execute()
bool AimCameratoFrontTaco::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AimCameratoFrontTaco::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimCameratoFrontTaco::Interrupted() {

}
