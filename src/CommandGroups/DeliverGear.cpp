/*
 * DeliverGear.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: celeste173
 */
#include "DeliverGear.h"
#include "Robot.h"

#include <math.h>

#include "../Commands/DriveToPosition.h"
#include "../Commands/RotateTo.h"
#include "../Commands/MoveBasedOnVision.h"

DeliverGear::DeliverGear(){
	double angle = Robot::gearLifterR;
	double rad = angle * M_PI / 180;
	double xposition = Robot::gearLifterX;
	double yposition = Robot::gearLifterY;
	double approachdist = 3*12; // line up 3 ft away from the gear lift
	double approachx = xposition - sin(rad)*approachdist;
	double approachy = yposition - cos(rad)*approachdist;
	AddSequential(new RotateTo(90+rad)); // align takko with gear lift
	AddSequential(new DriveToPosition(&approachx, &approachy));
	AddSequential(new MoveBasedOnVision());
}
