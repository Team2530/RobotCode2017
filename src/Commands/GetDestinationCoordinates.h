#ifndef GetDestinationCoordinates_H
#define GetDestinationCoordinates_H

#include "Commands/Command.h"
#include "../Subsystems/Tracker.h"

class GetDestinationCoordinates : public Command {
public:
	GetDestinationCoordinates();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GetDestinationCoordinates_H
