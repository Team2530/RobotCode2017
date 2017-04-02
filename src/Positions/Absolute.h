/*
 * Absolute.h
 *
 *  Created on: Feb 25, 2017
 *      Author: Nick
 */

#ifndef SRC_POSITIONS_ABSOLUTE_H_
#define SRC_POSITIONS_ABSOLUTE_H_

#include "../FieldPositions/FieldPosition.h"

class Absolute: public Position {
private:
	double positionx;
	double positiony;
	bool haverotation;
	double rotation;
public:
	Absolute(double x, double y);
	Absolute(double x, double y, double r);
	void UpdatePositionAbs(double* x, double* y, double* r) override;
	void Update(Position* updater);
};

#endif /* SRC_POSITIONS_ABSOLUTE_H_ */
