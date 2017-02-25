/*
 * BoilerFieldPosition.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: celeste173
 */

#include <FieldPositions/BoilerFieldPosition.h>
#include "Robot.h"
BoilerFieldPosition::BoilerFieldPosition() {
}
double BoilerFieldPosition::GetX(){
	return Robot::boilerX;
}
double BoilerFieldPosition::GetY(){
	return Robot::boilerY;
}
double BoilerFieldPosition::GetR(){
	return Robot::boilerR;
}

