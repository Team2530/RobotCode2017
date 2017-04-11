/*
 * DeliverFrontGear.cpp
 *
 *  Created on: April 1, 2017
 *      Author: TannerM
 */
#include "DeliverFrontGear.h"
#include "Robot.h"

#include "../Positions/Absolute.h"
#include "../Positions/RobotRelative.h"
#include "../FieldPositions/FieldPositionToRotateTo.h"
#include "../FieldPositions/GearFieldPosition.h"
#include "AimCameratoFrontTaco.h"
#include "LEDControl.h"
#include "DriveToPosition.h"
#include "Commands/MoveBasedOnVision.h"

DeliverFrontGear::DeliverFrontGear(){
	//double angle = 90;
	FieldPosition* gear = new GearFieldPosition();
	AddSequential(new LEDControl(true));
	AddSequential(new AimCameratoFrontTaco());
	AddSequential(new DriveToPosition(gear), 6.0); // Cut off this command after this amount of time
	AddSequential(new MoveBasedOnVision(36, gear), 2.0);
	AddSequential(new MoveBasedOnVision(30, gear), 1.5);
	AddSequential(new MoveBasedOnVision(24, gear), 1.5);
	// The vision is supposed to line up 3 feet away: drive forward that amount
	// Reserve 16-17 inches between the center of the robot and the lift
	AddSequential(new DriveToPosition(new RobotRelative(-25, 0)));
}

/*

enum DFGvariant {
	DFG_default,
	DFG_4sec,
	DFG_no2nd,
	DFG_4sec_no2nd,
	DFG_no1st,
	DFG_4sec_no1st
};

*/

DeliverFrontGear::DeliverFrontGear(DFGvariant variant){
	FieldPosition* gear = new GearFieldPosition();
	AddSequential(new LEDControl(true));
	AddSequential(new AimCameratoFrontTaco());
	double const firstDistance =  36.0;
	double const secondDistance = 30.0;
	//double const thirdDistance = 24.0;
	// TODO: Double check this distance with front takko
	double const lastDistance =  -31;//-25.0;

	if (variant == DFG_4sec) {
		AddSequential(new DriveToPosition(gear), 4.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(firstDistance, gear), 2.0);
		AddSequential(new MoveBasedOnVision(secondDistance, gear), 1.5);
		//AddSequential(new MoveBasedOnVision(thirdDistance, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(0, lastDistance)));
	} else if (variant == DFG_no2nd) {
		AddSequential(new DriveToPosition(gear), 6.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(firstDistance, gear), 2.0);
		//AddSequential(new MoveBasedOnVision(thirdDistance, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(0, lastDistance)));
	} else if (variant == DFG_4sec_no2nd) {
		AddSequential(new DriveToPosition(gear), 4.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(firstDistance, gear), 2.0);
		//AddSequential(new MoveBasedOnVision(thirdDistance, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(0, lastDistance)));
	} else if (variant == DFG_no1st) {
		AddSequential(new DriveToPosition(gear), 6.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(secondDistance, gear), 2.0);
		//AddSequential(new MoveBasedOnVision(thirdDistance, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(0, lastDistance)));
	} else if (variant == DFG_4sec_no1st) {
		AddSequential(new DriveToPosition(gear), 4.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(secondDistance, gear), 2.0);
	//	AddSequential(new MoveBasedOnVision(thirdDistance, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(0, lastDistance)));
	} else {
		FieldPosition* gear = new GearFieldPosition();
		AddSequential(new LEDControl(true));
		AddSequential(new AimCameratoFrontTaco());
		AddSequential(new DriveToPosition(gear), 6.0); // Cut off this command after this amount of time
		AddSequential(new MoveBasedOnVision(firstDistance, gear), 2.0);
		AddSequential(new MoveBasedOnVision(secondDistance, gear), 1.5);
	//	AddSequential(new MoveBasedOnVision(thirdDistance, gear), 1.5);
		// The vision is supposed to line up 3 feet away: drive forward that amount
		// Reserve 16-17 inches between the center of the robot and the lift
		AddSequential(new DriveToPosition(new RobotRelative(0, lastDistance)));
	}
}
