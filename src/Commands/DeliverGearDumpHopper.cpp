#include "DeliverGearDumpHopper.h"
#include "GetHopper.h"
#include "Robot.h"
#include "DriveToFieldPosition.h"
#include "IntakeOn.h"
#include "../FieldPositions/HopperFieldPosition.h"
#include "DeliverGear.cpp"
#include "GetHopper.cpp"

DeliverGearDumpHopper::DeliverGearDumpHopper() {
	// Add Commands here:

	AddSequential(new DeliverGear());
	AddSequential (new frc::WaitCommand(3));
	AddSequential (new GetHopper());


	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
