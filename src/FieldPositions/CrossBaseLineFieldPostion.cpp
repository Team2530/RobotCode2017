/*
 * CrossBaseLineFieldPostion.cpp
 *
 *  Created on: Mar 2, 2017
 *      Author: Admin
 */

#include <FieldPositions/CrossBaseLineFieldPostion.h>
#include  "Robot.h"

CrossBaseLineFieldPostion::CrossBaseLineFieldPostion() {
	// TODO Auto-generated constructor stub

}

double CrossBaseLineFieldPostion::GetX(){
	return Robot::positionBaseLineX;
}
double CrossBaseLineFieldPostion::GetY(){
	return Robot::positionBaseLineY;
}
double CrossBaseLineFieldPostion::GetR(){
	return Robot::positionBaseLineR;
}

