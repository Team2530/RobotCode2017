#include "DeliverFuel.h"

#include "GoToTarget.h"
#include "Dump.h"

#include "StartPositions.h"

DeliverFuel::DeliverFuel() {
	//AddSequential(new GoToTarget(x, *y));
	AddSequential(new Dump);
}
