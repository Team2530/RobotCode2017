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
#include "../Positions/Absolute.h"
#include "../Positions/RobotRelative.h"

DeliverGear::DeliverGear(){
	double angle = Robot::gearLifterR;
	double rad = angle * M_PI / 180;
	double xposition = Robot::gearLifterX;
	double yposition = Robot::gearLifterY;
	Absolute* approach = new Absolute(xposition, yposition, angle);
	// line up 3 ft away from the gear lift
	approach->Update(new RobotRelative(0, -3*12));
	AddSequential(new RotateTo(90+rad)); // align takko with gear lift
	AddSequential(new DriveToPosition(approach));
	AddSequential(new MoveBasedOnVision());
}
