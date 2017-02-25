/*
 * FieldRelative.h
 *
 *  Created on: Feb 25, 2017
 *      Author: Nick
 */

#ifndef SRC_POSITIONS_FIELDRELATIVE_H_
#define SRC_POSITIONS_FIELDRELATIVE_H_

#include <Positions/Position.h>

class FieldRelative: public Position {
private:
	double deltax;
	double deltay;
	double deltar;
public:
	FieldRelative(double dx, double dy, double dr = 0);
	void UpdatePositionAbs(double* x, double* y, double* r) override;
};

#endif /* SRC_POSITIONS_FIELDRELATIVE_H_ */
