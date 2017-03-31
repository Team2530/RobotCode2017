#include "MecanumDriveFieldOriented.h"
#include "Robot.h"

MecanumDriveFieldOriented::MecanumDriveFieldOriented() : Command("MecanumDriveFieldOriented") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void MecanumDriveFieldOriented::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MecanumDriveFieldOriented::Execute() {
	double currentAngle = Robot::tracker->GetCurrentAngle();
	Joystick* stick = Robot::oi->GetJoystick();
	double headingLockPID = Robot::autodrive->GetPIDRotation();
	bool enableHeadingLock = Robot::drivetrain->DriveWithCoordinates(
		stick->GetX(), stick->GetY(),
	  	stick->GetZ(), currentAngle,
		stick->GetThrottle(), headingLockPID
	);
	Robot::autodrive->EnableHeadingLock(enableHeadingLock);
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDriveFieldOriented::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MecanumDriveFieldOriented::End() {
	Robot::drivetrain->Stop();
	Robot::autodrive->EnableHeadingLock(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDriveFieldOriented::Interrupted() {
	Robot::drivetrain->Stop();
	Robot::autodrive->EnableHeadingLock(false);
}
