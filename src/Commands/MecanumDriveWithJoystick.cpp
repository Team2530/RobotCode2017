#include "MecanumDriveWithJoystick.h"

#include "Robot.h"

MecanumDriveWithJoystick::MecanumDriveWithJoystick(Orientation orient) : Command("MecanumDriveWithJoystick") {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());
	orientation = orient;
}

// Called just before this Command runs the first time
void MecanumDriveWithJoystick::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void MecanumDriveWithJoystick::Execute() {
	Robot::drivetrain->Drive(Robot::oi->GetJoystick(), orientation);
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MecanumDriveWithJoystick::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDriveWithJoystick::Interrupted() {
	Robot::drivetrain->Stop();
}
