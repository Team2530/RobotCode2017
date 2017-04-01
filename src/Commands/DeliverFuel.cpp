#include "DeliverFuel.h"

#include "Dump.h"
#include "Robot.h"
#include "DriveToPosition.h"
#include "../FieldPositions/BoilerFieldPosition.h"

DeliverFuel::DeliverFuel() {

	AddSequential(new DriveToPosition(new BoilerFieldPosition()));
	AddSequential(new Dump());
}
