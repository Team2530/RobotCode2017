/*
 * FieldPositionToRotateTo.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: Jason Mitchell
 */
#include "Robot.h"
#include <FieldPositions/FieldPositionToRotateTo.h>
FieldPositionToRotateTo::FieldPositionToRotateTo(double angle) {
	goal = angle;
}
double FieldPositionToRotateTo::GetX(){
	return Robot::tracker->GetCurrentPositionX();
}
double FieldPositionToRotateTo::GetY(){
	return Robot::tracker->GetCurrentPositionY();
}
double FieldPositionToRotateTo::GetR(){
	return goal;

}





