/*
 * DeliverGears.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Admin
 */

#ifndef SRC_COMMANDGROUPS_DELIVERGEARS_H_
#define SRC_COMMANDGROUPS_DELIVERGEARS_H_

#include "WPIlib.h"
#include "../Commands/LEDControl.h"
#include "../Commands/WaitForVision.h"
#include "../Commands/PullVisionEstimate.h"
#include "../Commands/MoveBasedOnVision.h"
#include "../Commands/FinalApproach.h"

class DeliverGears : public frc::CommandGroup {
	DeliverGears() {
		AddSequential(new LEDControl(true));
		AddSequential(new WaitForVision());
		AddSequential(new PullVisionEstimate());
		AddSequential(new MoveBasedOnVision());
		AddSequential(new WaitForVision());
		AddSequential(new PullVisionEstimate());
		AddSequential(new MoveBasedOnVision());
		AddSequential(new FinalApproach());
	}
}






#endif /* SRC_COMMANDGROUPS_DELIVERGEARS_H_ */
