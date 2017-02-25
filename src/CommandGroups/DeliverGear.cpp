/*
 * DeliverGears.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: celeste173
 */
#include "DeliverGear.h"
#include "Robot.h"

#include <math.h>

#include "../Commands/GoTo.h"
#include "../Commands/RotateTo.h"
#include "../Commands/MoveBasedOnVision.h"

DeliverGear::DeliverGear() {
	double angle = Robot::gearLifterR;
	double rad = angle * M_PI / 180;
	double goalX = Robot::gearLifterX;
	double goalY = Robot::gearLifterY;
	double approachdist = 3*12; // line up 3 ft away from the gear lift
	double approachX = goalX - sin(angle)*approachdist;
	double approachY = goalY - cos(angle)*approachdist;
	AddSequential(new RotateTo(90+angle)); // align takko with gear lift
	AddSequential(new GoTo(approachX, approachY));
	AddSequential(new MoveBasedOnVision());
}






