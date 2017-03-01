#include "GetHopper.h"
#include "Robot.h"
#include "DriveToFieldPosition.h"
#include "OrientRobot.h"
#include "IntakeOn.h"
#include "../FieldPositions/HopperFieldPosition.h"

GetHopper::GetHopper() {
	AddSequential(new DriveToFieldPosition(new HopperFieldPosition()));
	AddSequential(new IntakeOn());
}
