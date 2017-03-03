/*
 * GoToTarget.h
 *
 *  Created on: Feb 12, 2017
 *      Author: Shadotiz
 */

#ifndef SRC_COMMANDS_GOTOTARGET_H_
#define SRC_COMMANDS_GOTOTARGET_H_

#include "CalculateTargetAngle.h"
#include "DriveToPosition.h"

#include <Commands/CommandGroup.h>
// replace with FieldLocation

class GoToTarget : public CommandGroup {
public:
	GoToTarget(double *x,double *y);
private:
	double angle;
};

#endif /* SRC_COMMANDS_GOTOTARGET_H_ */
