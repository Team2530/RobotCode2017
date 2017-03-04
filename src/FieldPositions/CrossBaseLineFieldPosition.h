/*
 * CrossBaseLineFieldPosition.h
 *
 *  Created on: Mar 2, 2017
 *      Author: Admin
 */

#ifndef SRC_FIELDPOSITIONS_CROSSBASELINEFIELDPOSITION_H_
#define SRC_FIELDPOSITIONS_CROSSBASELINEFIELDPOSITION_H_

#include <FieldPositions/FieldPosition.h>

class CrossBaseLineFieldPosition: public FieldPosition {
public:
	virtual double GetX();
	virtual double GetY();
	virtual double GetR();
	CrossBaseLineFieldPosition();
};

#endif /* SRC_FIELDPOSITIONS_CROSSBASELINEFIELDPOSITION_H_ */
