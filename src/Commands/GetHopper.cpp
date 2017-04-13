#include "GetHopper.h"
#include "Robot.h"
#include "DriveToPosition.h"
#include "../FieldPositions/HopperFieldPosition.h"

GetHopper::GetHopper() {
	AddSequential(new DriveToPosition(new HopperFieldPosition()));
}
