/*
 * GoToTarget.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: Shadotiz
 */

#include "GoToTarget.h"
#include "Commands/OrientRobot.h"
#include "../Positions/Absolute.h"

GoToTarget::GoToTarget(double *x, double *y)
{
	AddSequential(new CalculateTargetAngle(x, y, &angle));
	AddSequential(new OrientRobot(&angle));
	AddSequential(new DriveToPosition(new Absolute(*x, *y)));
}
