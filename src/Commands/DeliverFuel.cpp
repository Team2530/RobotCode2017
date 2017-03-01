#include "DeliverFuel.h"

#include "Dump.h"
#include "Robot.h"
#include "DriveToFieldPosition.h"
#include "StartPositions.h"
#include "../FieldPositions/BoilerFieldPosition.h"

DeliverFuel::DeliverFuel() {
	AddSequential(new DriveToFieldPosition(new BoilerFieldPosition()));
	AddSequential(new Dump());
}
