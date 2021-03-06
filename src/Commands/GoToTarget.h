/*
 * GoToTarget.h
 *
 *  Created on: Feb 12, 2017
 *      Author: Shadotiz
 */

#ifndef SRC_COMMANDS_GOTOTARGET_H_
#define SRC_COMMANDS_GOTOTARGET_H_

#include "CalculateTargetAngle.h"
#include "DriveForward.h"

#include <Commands/CommandGroup.h>

class GoToTarget : public CommandGroup {
public:
	GoToTarget(double *angle, double *x,double *y);

};

#endif /* SRC_COMMANDS_GOTOTARGET_H_ */
