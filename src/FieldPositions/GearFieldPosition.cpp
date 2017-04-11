/*
 * GearFieldPosition.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: celeste173
 */

#include <FieldPositions/GearFieldPosition.h>
#include "Robot.h"

GearFieldPosition::GearFieldPosition() {
}
double GearFieldPosition::GetX(){
	return Robot::gearLifterX;
}
double GearFieldPosition::GetY(){
	return Robot::gearLifterY;
}
double GearFieldPosition::GetR(){
	double orientation = Robot::cameraservo->facing; // TAKKO_FOWARD or FRONT_FORWARD
	return Robot::gearLifterR + orientation;
}
