/*
 * RobotRelative.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: Nick
 */

#include <Positions/RobotRelative.h>
#include <math.h>

RobotRelative::RobotRelative(double right, double forward, double rotation, bool absrotation) {
	distr = right;
	distf = forward;
	rot = rotation;
	rotation_abs = absrotation;
}
void RobotRelative::UpdatePositionAbs(double* x, double* y, double* r) {
	double rad = (*r) * M_PI / 180;
	double dx =  distr*cos(rad) + distf*sin(rad);
	double dy = -distr*sin(rad) + distf*cos(rad);
	*x += dx;
	*y += dy;
	if (rotation_abs) {
		*r = rot;
	} else {
		*r += rot;
	}
}
