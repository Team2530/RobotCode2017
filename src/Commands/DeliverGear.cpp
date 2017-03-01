/*
 * DeliverGear.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: celeste173
 */
#include "DeliverGear.h"
#include "Robot.h"

#include <math.h>

#include "../Commands/DriveToFieldPosition.h"
#include "../Commands/DriveToPosition.h"
#include "../Commands/MoveBasedOnVision.h"
#include "../Positions/Absolute.h"
#include "../Positions/RobotRelative.h"
#include "../FieldPositions/FieldPositionToRotateTo.h"

DeliverGear::DeliverGear(){
	double angle = Robot::gearLifterR;
	double rad = angle * M_PI / 180;
	double xposition = Robot::gearLifterX;
	double yposition = Robot::gearLifterY;
	Absolute* approach = new Absolute(xposition, yposition, angle);
	// line up 3 ft away from the gear lift
	// update rotation by 90 degrees to put takko forward
	approach->Update(new RobotRelative(0, -3*12, 90));
	AddSequential(new DriveToPosition(approach));
	AddSequential(new MoveBasedOnVision());
	// The vision is supposed to line up 3 feet away: drive forward that amount
	// Reserve 16-17 inches between the center of the robot and the lift
	AddSequential(new DriveToPosition(new RobotRelative(0, 3*12 - 17)));
}
