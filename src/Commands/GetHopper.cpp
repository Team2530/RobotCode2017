#include "GetHopper.h"
#include "Robot.h"
#include "DriveToPosition.h"
#include "OrientRobot.h"
#include "IntakeOn.h"
GetHopper::GetHopper() {
	double *x = &Robot::hopperX;
	double *y = &Robot::hopperY;
	double *r = &Robot::hopperR;
	AddSequential(new DriveToPosition(x, y));
	AddSequential(new OrientRobot(r));
	AddSequential(new IntakeOn);




}
