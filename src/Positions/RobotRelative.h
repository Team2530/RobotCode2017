/*
 * RobotRelative.h
 *
 *  Created on: Feb 25, 2017
 *      Author: Nick
 */

#ifndef SRC_POSITIONS_ROBOTRELATIVE_H_
#define SRC_POSITIONS_ROBOTRELATIVE_H_

#include <Positions/Position.h>

class RobotRelative: public Position {
private:
	double distr;
	double distf;
	double rot;
public:
	RobotRelative(double right, double forward, double rotation = 0);
	void UpdatePositionAbs(double* x, double* y, double* r) override;
};

#endif /* SRC_POSITIONS_ROBOTRELATIVE_H_ */
