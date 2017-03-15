#ifndef DeliverGearThenHopper_H
#define DeliverGearThenHopper_H

#include <Commands/CommandGroup.h>
#include "DeliverGear.h"
#include "Dump.h"
#include "Robot.h"
#include "DriveToFieldPosition.h"
#include "..//FieldPositions/HopperFieldPosition.h"
class DeliverGearThenHopper : public Commands {
public:
	DeliverGearThenHopper();
};

#endif  // DeliverGearThenDump_H
