#include "ApproachGear.h"

#include "../Robot.h"
#include "../Positions/Absolute.h"
#include "../Positions/RobotRelative.h"
#include "../FieldPositions/GearFieldPosition.h"

ApproachGear::ApproachGear() {
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void ApproachGear::Initialize() {
	Absolute* approach = new Absolute(new GearFieldPosition());
	// line up 3 ft away from the gear lift
	// update rotation by 90 degrees to put takko forward
	//approach->Update(new RobotRelative(0, -3*12, 90));
	Robot::tracker->PIDReset();
	Robot::tracker->MoveToPos(approach);
}

// Called repeatedly when this Command is scheduled to run
void ApproachGear::Execute() {
	Robot::tracker->GetPosition();
	Robot::tracker->Drive(Robot::drivetrain.get());
}

// Make this return true when this Command no longer needs to run execute()
bool ApproachGear::IsFinished() {
	return Robot::tracker->PIDFinished();
}

// Called once after isFinished returns true
void ApproachGear::End() {
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ApproachGear::Interrupted() {
	Robot::tracker->PIDDisable();
	Robot::drivetrain->Stop();
}
