/*
 * BoilerFieldPosition.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: celeste173
 */
#include "Robot.h"
#include <FieldPositions/BoilerFieldPosition.h>

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

