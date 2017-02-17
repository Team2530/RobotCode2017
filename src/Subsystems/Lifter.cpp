#include "Lifter.h"
#include "../RobotMap.h"

Lifter::Lifter() : Subsystem("ExampleSubsystem") {
jaguar=new Jaguar (kliftermotor=5);
}

void Lifter::InitDefaultCommand() {

	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
