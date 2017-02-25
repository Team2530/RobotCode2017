#include "DeliverFuel.h"

#include "Dump.h"
#include "Robot.h"
#include "DriveToPosition.h"
#include "OrientRobot.h"
#include "StartPositions.h"

DeliverFuel::DeliverFuel() {
	double *x = &Robot::boilerX;
	double *y = &Robot::boilerY;
	double *r = &Robot::boilerR;
	AddSequential(new DriveToPosition(x, y));
	AddSequential(new OrientRobot(r));
	AddSequential(new Dump);



}
