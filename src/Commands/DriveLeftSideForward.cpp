/*
 * DriveLeftSideForward.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: Shadotiz
 */

#include "DriveLeftSideForward.h"

#include "../Orientation.h"

#include "Robot.h"
DriveLeftSideForward::DriveLeftSideForward():Command("DriveLeftSideForward") {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());;
}

// Called just before this Command runs the first time
void DriveLeftSideForward::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveLeftSideForward::Execute() {
	Robot::drivetrain->Drive(Robot::oi->GetJoystick(), TAKKO_FORWARD);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveLeftSideForward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveLeftSideForward::End() {
	Robot::drivetrain->Stop();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLeftSideForward::Interrupted() {
	Robot::drivetrain->Stop();
}


