#include "MecanumDriveFieldOriented.h"

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
	Robot::drivetrain->DriveWithCoordinates(stick.GetX(), stick.GetY(),
			stick.GetZ(),ahrs->GetAngle());
	Robot::drivetrain->Drive(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDriveFieldOriented::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MecanumDriveFieldOriented::End() {
	Robot::drivetrain->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDriveFieldOriented::Interrupted() {
	Robot::drivetrain->Stop();
}
