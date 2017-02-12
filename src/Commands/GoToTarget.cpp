/*
 * GoToTarget.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: Shadotiz
 */

#include "GoToTarget.h"

GoToTarget::GoToTarget(double x, double y)
{
	AddSequential(new OrientRobot(x, y));
	AddSequential(new DriveForward(x, y));
}
