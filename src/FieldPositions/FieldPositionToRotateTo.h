/*
 * FieldPositionToRotateTo.h
 *
 *  Created on: Feb 28, 2017
 *      Author: Jason Mitchell
 */
#include "FieldPosition.h"
#ifndef SRC_FIELDPOSITIONS_FIELDPOSITIONTOROTATETO_H_
#define SRC_FIELDPOSITIONS_FIELDPOSITIONTOROTATETO_H_
class FieldPositionToRotateTo : public FieldPosition {
private:
	double goal;
public:
	FieldPositionToRotateTo(double angle);
	double GetX();
	double GetY();
	double GetR();
};




#endif /* SRC_FIELDPOSITIONS_FIELDPOSITIONTOROTATETO_H_ */
