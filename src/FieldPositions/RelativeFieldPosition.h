/*
 * RelativeFieldPosition.h
 *
 *  Created on: Mar 2, 2017
 *      Author: Owner
 */

#ifndef SRC_FIELDPOSITIONS_RELATIVEFIELDPOSITION_H_
#define SRC_FIELDPOSITIONS_RELATIVEFIELDPOSITION_H_

#include <FieldPositions/FieldPosition.h>

class RelativeFieldPosition: public FieldPosition {
public:

	RelativeFieldPosition(double x, double y, double angle);
	virtual double getX() = 0;
	virtual double getY() = 0;
	virtual double getR() = 0;

	double changeInX;
	double changeInY;
	double changeInAngle;




};

#endif /* SRC_FIELDPOSITIONS_RELATIVEFIELDPOSITION_H_ */
