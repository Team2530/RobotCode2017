/*
 * BoilerFieldPosition.h
 *
 *  Created on: Feb 25, 2017
 *      Author: celeste173
 */
#include "FieldPosition.h"
#ifndef SRC_FIELDPOSITIONS_BOILERFIELDPOSITION_H_
#define SRC_FIELDPOSITIONS_BOILERFIELDPOSITION_H_

class BoilerFieldPosition : public FieldPosition {
public:
	BoilerFieldPosition();
	double GetX();
	double GetY();
	double GetR();
};

#endif /* SRC_FIELDPOSITIONS_BOILERFIELDPOSITION_H_ */
