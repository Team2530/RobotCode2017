/*
 * Position.h
 *
 *  Created on: Feb 25, 2017
 *      Author: Nick
 */

#ifndef SRC_POSITIONS_POSITION_H_
#define SRC_POSITIONS_POSITION_H_

class Position {
public:
	virtual void UpdatePositionAbs(double* x, double* y, double* r) = 0;
};



#endif /* SRC_POSITIONS_POSITION_H_ */
