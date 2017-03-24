/*
 * DeliverGear.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Admin
 */

#ifndef SRC_COMMANDGROUPS_DELIVERGEAR_H_
#define SRC_COMMANDGROUPS_DELIVERGEAR_H_

#include "WPIlib.h"
#include "DriverStation.h"
//#include "../Tracker.h"//??need??
//#include "GetFieldPosition.h"
#include "Commands/Command.h"
#include "Commands/CommandGroupEntry.h"
#include "../StartPositions.h"

enum DGvariant {
	DG_default,
	DG_4sec,
	DG_no2nd,
	DG_4sec_no2nd,
	DG_no1st,
	DG_4sec_no1st
};

class DeliverGear : public frc::CommandGroup {
	public:
		DeliverGear();
		DeliverGear(DGvariant variant);
};

#endif /* SRC_COMMANDGROUPS_DELIVERGEAR_H_ */
