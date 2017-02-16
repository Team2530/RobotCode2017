/*
 * DeliverGears.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: celeste173
 */
#include "DeliverGear.h"
#include "Robot.h"

DeliverGear::DeliverGear(StartPosition aPosition, Objects aTarget){
	frc::DriverStation::Alliance team = DriverStation::GetInstance().Getfrc::DriverStation::Alliance();
	AddSequential(new TrackerInit(aPosition, team));
	AddSequential(new GetDestinationCoordinatesX(aTarget, team))
	//AddSequential(new GetFieldPosition());
}






