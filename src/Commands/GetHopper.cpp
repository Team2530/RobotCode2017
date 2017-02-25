#include "GetHopper.h"
#include "Robot.h"
#include "OrientRobot.h"
#include "DriveToPosition.h"
#include "IntakeOn.h"
GetHopper::GetHopper() {
	double *x = &Robot::hopperX;
	double *y = &Robot::hopperY;
	double *r = &Robot::hopperR;
	AddSequential(new OrientRobot(r));
	AddSequential(new DriveToPosition(x, y));
	AddSequential(new IntakeOn);
	//TODO::add ability for robot to strafe back and forth to collect balls during Autonomous



}
