/*
 * IntakeInvert.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Jason or Jared
 */
#include "IntakeInvert.h"

#include "Robot.h"
IntakeInvert::IntakeInvert():Command("IntakeInvert") {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void IntakeInvert::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void IntakeInvert::Execute() {
	Robot::intake->Intake::IntakeInvert();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeInvert::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeInvert::End() {
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeInvert::Interrupted() {
}






