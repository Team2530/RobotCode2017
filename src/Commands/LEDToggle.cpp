#include <Commands/LEDToggle.h>
#include "../Robot.h"

LEDToggle::LEDToggle() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::led.get());

}

// Called just before this Command runs the first time
void LEDToggle::Initialize() {
	Robot::led->Toggle();
}

// Called repeatedly when this Command is scheduled to run
void LEDToggle::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LEDToggle::IsFinished() {
  return true;

}

// Called once after isFinished returns true
void LEDToggle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LEDToggle::Interrupted() {

}
