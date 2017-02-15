/*
 * GoToTarget.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: Shadotiz
 */

#include "GoToTarget.h"

GoToTarget::GoToTarget(double *angle, double *x, double *y)
{
	AddSequential(new CalculateTargetAngle(angle));
	AddSequential(new DriveForward(x, y));
}
