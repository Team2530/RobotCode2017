/*
 * DeliverFrontGear.h
 *
 *  Created on: April 1, 2017
 *      Author: TannerM
 */

#ifndef SRC_COMMANDGROUPS_DELIVERFRONTGEAR_H_
#define SRC_COMMANDGROUPS_DELIVERFRONTGEAR_H_

#include "WPIlib.h"
//#include "../Tracker.h"//??need??
//#include "GetFieldPosition.h"
#include "../StartPositions.h"

enum DFGvariant {
	DFG_default,
	DFG_4sec,
	DFG_no2nd,
	DFG_4sec_no2nd,
	DFG_no1st,
	DFG_4sec_no1st
};

class DeliverFrontGear : public frc::CommandGroup {
	public:
		DeliverFrontGear();
		DeliverFrontGear(DFGvariant variant);
};

#endif /* SRC_COMMANDGROUPS_DELIVERFRONTGEAR_H_ */
