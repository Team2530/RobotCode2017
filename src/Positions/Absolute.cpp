/*
 * Absolute.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: Nick
 */

#include <Positions/Absolute.h>

Absolute::Absolute(double x, double y) {
	positionx = x;
	positiony = y;
	haverotation = false;
	rotation = 0;
}
Absolute::Absolute(double x, double y, double r) {
	positionx = x;
	positiony = y;
	haverotation = true;
	rotation = r;
}

void Absolute::UpdatePositionAbs(double* x, double* y, double* r) {
	*x = positionx;
	*y = positiony;
	if (haverotation) {
		*r = rotation;
	}
}

void Absolute::Update(RobotRelative updater) {
	updater.UpdatePositionAbs(&positionx, &positiony, &rotation);
}

