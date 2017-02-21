#include "CrossBaseLine.h"
#include "Robot.h"
#include "math.h"

CrossBaseLine::CrossBaseLine() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

	Requires(Robot::drivetrain.get());
	Requires(Robot::tracker.get());
}

// Called just before this Command runs the first time
void CrossBaseLine::Initialize() {

	Robot::tracker->MoveToAbs(Robot::tracker->GetCurrentPositionX(),92.75);
}

// Called repeatedly when this Command is scheduled to run
void CrossBaseLine::Execute() {
//where 112 = 93.25 + robot distance
	Robot::tracker->GetPosition();
	Robot::drivetrain->Track(Robot::tracker.get());
}

// Make this return true when this Command no longer needs to run execute()
bool CrossBaseLine::IsFinished() {

	return Robot::tracker->PIDFinished();
}

// Called once after isFinished returns true
void CrossBaseLine::End() {

	Robot::tracker->PIDReset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CrossBaseLine::Interrupted() {

	Robot::tracker->PIDReset();
}
