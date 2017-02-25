/*
 * HopperFieldPosition.h
 *
 *  Created on: Feb 25, 2017
 *      Author: celeste173
 */
#include "FieldPosition.h"
#ifndef SRC_FIELDPOSITIONS_HOPPERFIELDPOSITION_H_
#define SRC_FIELDPOSITIONS_HOPPERFIELDPOSITION_H_

class HopperFieldPosition : public FieldPosition{
public:
	HopperFieldPosition();
	double GetX();
	double GetY();
	double GetR();
};

#endif /* SRC_FIELDPOSITIONS_HOPPERFIELDPOSITION_H_ */
