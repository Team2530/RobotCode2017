/*
 * DeliverGear.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: celeste173
 */
#include "DeliverGear.h"
#include "Robot.h"

#include <math.h>

#include "../Commands/ApproachGear.h"
#include "../Commands/DriveToFieldPosition.h"
#include "../Commands/DriveToPosition.h"
#include "../Commands/MoveBasedOnVision.h"
#include "../Positions/Absolute.h"
#include "../Positions/RobotRelative.h"
#include "../FieldPositions/FieldPositionToRotateTo.h"

DeliverGear::DeliverGear(){
	AddSequential(new ApproachGear());
	AddSequential(new MoveBasedOnVision());
	// The vision is supposed to line up 3 feet away: drive forward that amount
	// Reserve 16-17 inches between the center of the robot and the lift
	AddSequential(new DriveToPosition(new RobotRelative(0, 3*12 - 17)));
}
