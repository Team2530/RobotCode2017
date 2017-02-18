#include "AimCameratoLift.h"
#include "Robot.h"

AimCameratoLift::AimCameratoLift() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::cameraservo.get());
}

// Called just before this Command runs the first time
void AimCameratoLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AimCameratoLift::Execute() {
	Robot::cameraservo->Aim(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool AimCameratoLift::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AimCameratoLift::End() {
	Robot::cameraservo->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimCameratoLift::Interrupted() {
	Robot::cameraservo->Stop();
}
