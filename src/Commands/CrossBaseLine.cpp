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

}

// Called repeatedly when this Command is scheduled to run
void CrossBaseLine::Execute() {
//where 112 = 93.25 + robot distance
	Robot::drivetrain->DriveWithCoordinates(Robot::tracker->GetCurrentPositionX(),92.75,0,0);//rough coordinates of baseline
}

// Make this return true when this Command no longer needs to run execute()
bool CrossBaseLine::IsFinished() {
	if (abs(Robot::tracker->GetCurrentPositionX()-Robot::initialX) < 112 && Robot::tracker->GetCurrentPositionY()<112){
		return false;
	}
	else{
		return true;
	}
}

// Called once after isFinished returns true
void CrossBaseLine::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CrossBaseLine::Interrupted() {

}
