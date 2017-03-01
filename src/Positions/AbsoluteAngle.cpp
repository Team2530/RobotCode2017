/*
 * AbsoluteAngle.cpp
 *
 *  Created on: Feb 28, 2017
 *      Author: Nick
 */

#include <Positions/AbsoluteAngle.h>

AbsoluteAngle::AbsoluteAngle(double r) {
	angle = r;
}

void AbsoluteAngle::UpdatePositionAbs(double* x, double* y, double* r) {
	*r = angle;
}

