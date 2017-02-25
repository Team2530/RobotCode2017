/*
 * FieldRelative.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: Nick
 */

#include <Positions/FieldRelative.h>

FieldRelative::FieldRelative(double dx, double dy, double dr) {
	deltax = dx;
	deltay = dy;
	deltar = dr;
}

void FieldRelative::UpdatePositionAbs(double* x, double* y, double* r) {
	*x += deltax;
	*y += deltay;
	*r += deltar;
}
