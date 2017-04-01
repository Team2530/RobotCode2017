#include "Robot.h"
#include "AimCameratoTaco.h"

AimCameratoTaco::AimCameratoTaco() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::cameraservo.get());
}

// Called just before this Command runs the first time
void AimCameratoTaco::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AimCameratoTaco::Execute() {
	Robot::cameraservo->AimTaco();
}

// Make this return true when this Command no longer needs to run execute()
bool AimCameratoTaco::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AimCameratoTaco::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimCameratoTaco::Interrupted() {

}
