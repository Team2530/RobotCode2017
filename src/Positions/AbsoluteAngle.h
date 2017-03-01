/*
 * AbsoluteAngle.h
 *
 *  Created on: Feb 28, 2017
 *      Author: Nick
 */

#ifndef SRC_POSITIONS_ABSOLUTEANGLE_H_
#define SRC_POSITIONS_ABSOLUTEANGLE_H_

#include <Positions/Position.h>

class AbsoluteAngle: public Position {
private:
	double angle;
public:
	AbsoluteAngle(double r);
	void UpdatePositionAbs(double* x, double* y, double* r) override;
};

#endif /* SRC_POSITIONS_ABSOLUTEANGLE_H_ */
