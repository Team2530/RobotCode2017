/*
 * IntakeOn.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: Jason
 */
#include "IntakeOn.h"

#include "Robot.h"
IntakeOn::IntakeOn():Command("IntakeOn") {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void IntakeOn::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void IntakeOn::Execute() {
	Robot::intake->Intake::IntakeOn();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeOn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeOn::End() {
	Robot::intake->IntakeOff();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeOn::Interrupted() {
	Robot::intake->IntakeOff();
}


