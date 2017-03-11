/*
 * DriveRightSideForward.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: Shadotiz
 */

#include "DriveRightSideForward.h"

#include "../Orientation.h"

#include "Robot.h"
DriveRightSideForward::DriveRightSideForward():Command("DriveRightSideForward") {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::drivetrain.get());;
}

// Called just before this Command runs the first time
void DriveRightSideForward::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveRightSideForward::Execute() {
	Robot::drivetrain->Drive(Robot::oi->GetJoystick(), DUMP_FORWARD);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveRightSideForward::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveRightSideForward::End() {
	Robot::drivetrain->Stop();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveRightSideForward::Interrupted() {
	Robot::drivetrain->Stop();
}


