#include "DriveToFieldPosition.h"
#include "Robot.h"
#include "Subsystems/Tracker.h"
#include "FieldPositions/FieldPosition.h"
DriveToFieldPosition::DriveToFieldPosition(FieldPosition *FP) {
	FieldP = FP;
	Requires(Robot::tracker.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void DriveToFieldPosition::Initialize() {
	Robot::tracker->Set(FieldP->getX(), FieldP->getY(), FieldP->getR());
}

// Called repeatedly when this Command is scheduled to run
void DriveToFieldPosition::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveToFieldPosition::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveToFieldPosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToFieldPosition::Interrupted() {

}
