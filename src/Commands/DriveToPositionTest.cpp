#include <Commands/DriveToPositionTest.h>																	//Does not stop!
#include "../Robot.h"

DriveToPositionTest::DriveToPositionTest(Position *p)
	: DriveToPosition(p)
{
}
DriveToPositionTest::DriveToPositionTest(Position *p, double speed)
	: DriveToPosition(p, speed)
{
}

// Return false to keep the command running to see PID oscillation
bool DriveToPositionTest::IsFinished() {
	return false;
}
