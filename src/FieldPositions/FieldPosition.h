/*
 * FieldPosition.h
 *
 *  Created on: Feb 25, 2017
 *      Author: celeste173
 */

#ifndef SRC_FIELDPOSITIONS_FIELDPOSITION_H_
#define SRC_FIELDPOSITIONS_FIELDPOSITION_H_

#include "../Positions/Position.h"

class FieldPosition : public Position {
public:
	virtual double GetX() = 0;
	virtual double GetY() = 0;
	virtual double GetR() = 0;
	void UpdatePositionAbs(double* x, double* y, double* r) override {
		*x = GetX();
		*y = GetY();
		*r = GetR();
	}
};



#endif /* SRC_FIELDPOSITIONS_FIELDPOSITION_H_ */
