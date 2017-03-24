/*
 * DeliverGear.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: celeste173
 */
#include "DeliverGear.h"
#include "Robot.h"

#include <math.h>

#include "../Commands/LEDControl.h"
#include "../Commands/AimCameratoTaco.h"
#include "../Commands/ApproachGear.h"
#include "../Commands/DriveToFieldPosition.h"
#include "../Commands/DriveToPosition.h"
#include "../Commands/MoveBasedOnVision.h"
#include "../Positions/Absolute.h"
#include "../Positions/RobotRelative.h"
#include "../FieldPositions/FieldPositionToRotateTo.h"
#include "../FieldPositions/GearFieldPosition.h"

DeliverGear::DeliverGear(){
	//double angle = 90;
	FieldPosition* gear = new GearFieldPosition();
	AddSequential(new LEDControl(true));
	AddSequential(new AimCameratoTaco());
	AddSequential(new DriveToFieldPosition(gear), 6.0); // Cut off this command after this amount of time
	AddSequential(new MoveBasedOnVision(36, gear), 2.0);
	AddSequential(new MoveBasedOnVision(30, gear), 1.5);
	AddSequential(new MoveBasedOnVision(24, gear), 1.5);
	// The vision is supposed to line up 3 feet away: drive forward that amount
	// Reserve 16-17 inches between the center of the robot and the lift
	AddSequential(new DriveToPosition(new RobotRelative(-25, 0)));
}

/*

enum DGvariant {
	DG_default,
	DG_4sec,
	DG_no2nd,
	DG_4sec_no2nd,
	DG_no1st,
	DG_4sec_no1st
};

*/

DeliverGear::DeliverGear(DGvariant variant){
	FieldPosition* gear = new GearFieldPosition();
	AddSequential(new LEDControl(true));
	AddSequential(new AimCameratoTaco());
	if (variant == DG_4sec) {
		AddSequential(new DriveToFieldPosition(gear), 4.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(36, gear), 2.0);
		AddSequential(new MoveBasedOnVision(30, gear), 1.5);
		AddSequential(new MoveBasedOnVision(24, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(-25, 0)));
	} else if (variant == DG_no2nd) {
		AddSequential(new DriveToFieldPosition(gear), 6.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(36, gear), 2.0);
		AddSequential(new MoveBasedOnVision(24, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(-25, 0)));
	} else if (variant == DG_4sec_no2nd) {
		AddSequential(new DriveToFieldPosition(gear), 4.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(36, gear), 2.0);
		AddSequential(new MoveBasedOnVision(24, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(-25, 0)));
	} else if (variant == DG_no1st) {
		AddSequential(new DriveToFieldPosition(gear), 6.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(30, gear), 2.0);
		AddSequential(new MoveBasedOnVision(24, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(-25, 0)));
	} else if (variant == DG_4sec_no1st) {
		AddSequential(new DriveToFieldPosition(gear), 4.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(30, gear), 2.0);
		AddSequential(new MoveBasedOnVision(24, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(-25, 0)));
	} else {
		FieldPosition* gear = new GearFieldPosition();
		AddSequential(new LEDControl(true));
		AddSequential(new AimCameratoTaco());
		AddSequential(new DriveToFieldPosition(gear), 6.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(36, gear), 2.0);
		AddSequential(new MoveBasedOnVision(30, gear), 1.5);
		AddSequential(new MoveBasedOnVision(24, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(-25, 0)));
	}
}
