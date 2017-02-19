#include "LEDControl.h"

LEDControl::LEDControl(bool on) {
	// Use Requires() here to declare subsystem dependencies
	value = on;
	Requires(Robot::led.get());
}

// Called just before this Command runs the first time
void LEDControl::Initialize() {
	Robot::led->Set(value);
}

// Called repeatedly when this Command is scheduled to run
void LEDControl::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LEDControl::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void LEDControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LEDControl::Interrupted() {

}
