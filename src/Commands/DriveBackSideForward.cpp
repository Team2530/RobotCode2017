/*
 * DriveBackSideForward.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: Shadotiz
 */

#include "DriveBackSideForward.h"

#include "../Orientation.h"

#include "Robot.h"
DriveBackSideForward::DriveBackSideForward():Command("DriveBackSideForward") {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());;
}

// Called just before this Command runs the first time
void DriveBackSideForward::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveBackSideForward::Execute() {
	Robot::drivetrain->Drive(Robot::oi->GetJoystick(), CLIMBER_FORWARD);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveBackSideForward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveBackSideForward::End() {
	Robot::drivetrain->Stop();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveBackSideForward::Interrupted() {
	Robot::drivetrain->Stop();
}


