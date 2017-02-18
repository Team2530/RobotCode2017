#include "DriveLeft.h"

#include "Robot.h"
DriveLeft::DriveLeft():Command("DriveLeft") {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::drivetrain.get());;
}

// Called just before this Command runs the first time
void DriveLeft::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveLeft::Execute() {
  Robot::drivetrain->DriveLeft();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveLeft::IsFinished() {
  return false;
}

// Called once after isFinished returns true
void DriveLeft::End() {
  Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLeft::Interrupted() {
  Robot::drivetrain->Stop();
