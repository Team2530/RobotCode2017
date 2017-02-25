/*
 * HopperFieldPosition.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: celeste173
 */

#include <FieldPositions/HopperFieldPosition.h>

HopperFieldPosition::HopperFieldPosition() {
}
double HopperFieldPosition::GetX(){
	return Robot::hopperX;
}
double HopperFieldPosition::GetY(){
	return Robot::hopperY;
}
double HopperFieldPosition::GetR(){
	return Robot::hopperR;
}


