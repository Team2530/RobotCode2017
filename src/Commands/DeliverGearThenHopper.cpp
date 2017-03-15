#include "DeliverGearThenHopper.h"

DeliverGearThenHopper::DeliverGearThenHopper() {
	AddSequential(new DeliverGear());
	AddSequential(new WaitUntilCommand(7));
	AddSequential(new DriveToFieldPosition(HopperFieldPosition));
}
