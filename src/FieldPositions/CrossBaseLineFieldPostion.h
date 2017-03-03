/*
 * CrossBaseLineFieldPostion.h
 *
 *  Created on: Mar 2, 2017
 *      Author: Admin
 */

#ifndef SRC_FIELDPOSITIONS_CROSSBASELINEFIELDPOSTION_H_
#define SRC_FIELDPOSITIONS_CROSSBASELINEFIELDPOSTION_H_

#include <FieldPositions/FieldPosition.h>

class CrossBaseLineFieldPostion: public FieldPosition {
public:
	virtual double GetX();
	virtual double GetY();
	virtual double GetR();
	CrossBaseLineFieldPostion();
};

#endif /* SRC_FIELDPOSITIONS_CROSSBASELINEFIELDPOSTION_H_ */
