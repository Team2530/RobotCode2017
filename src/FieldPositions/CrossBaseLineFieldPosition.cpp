/*
 * CrossBaseLineFieldPostion.cpp
 *
 *  Created on: Mar 2, 2017
 *      Author: Admin
 */

#include <FieldPositions/CrossBaseLineFieldPosition.h>
#include  "Robot.h"

CrossBaseLineFieldPosition::CrossBaseLineFieldPosition() {
	// TODO Auto-generated constructor stub

}

double CrossBaseLineFieldPosition::GetX(){
	return Robot::positionBaseLineX;
}
double CrossBaseLineFieldPosition::GetY(){
	return Robot::positionBaseLineY;
}
double CrossBaseLineFieldPosition::GetR(){
	return Robot::positionBaseLineR;
}

