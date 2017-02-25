/*
 * GearFieldPosition.h
 *
 *  Created on: Feb 25, 2017
 *      Author: celeste173
 */
#include "FieldPosition.h";
#ifndef SRC_FIELDPOSITIONS_GEARFIELDPOSITION_H_
#define SRC_FIELDPOSITIONS_GEARFIELDPOSITION_H_

class GearFieldPosition : public FieldPosition {
public:
	GearFieldPosition();
	double GetX();
	double GetY();
	double GetR();
};

#endif /* SRC_FIELDPOSITIONS_GEARFIELDPOSITION_H_ */
