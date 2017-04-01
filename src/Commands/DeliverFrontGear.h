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

enum DGvariant {
	DG_default,
	DG_4sec,
	DG_no2nd,
	DG_4sec_no2nd,
	DG_no1st,
	DG_4sec_no1st
};

class DeliverFrontGear : public frc::CommandGroup {
	public:
		DeliverFrontGear();
		DeliverFrontGear(DGvariant variant);
};

#endif /* SRC_COMMANDGROUPS_DELIVERFRONTGEAR_H_ */
