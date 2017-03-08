#include "PerimeterMovement.h"
#include "DriveToPosition.h"
#include "../Positions/Absolute.h"
#include "Robot.h"
PerimeterMovement::PerimeterMovement() {
	const double DISTANCE = 50;
	AddSequential(new DriveToPosition(new Absolute(DISTANCE,0)));
	AddSequential(new DriveToPosition(new Absolute(DISTANCE,DISTANCE)));
	AddSequential(new DriveToPosition(new Absolute(0,DISTANCE)));
	AddSequential(new DriveToPosition(new Absolute(0,0)));
}
