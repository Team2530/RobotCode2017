#ifndef DriveDistanceForward_H
#define DriveDistanceForward_H

#include "Commands/Command.h"

class DriveDistanceForward : public Command {
public:
	double *driveDistanceForward;
	DriveDistanceForward(double *distanceToTravel);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveDistanceForward_H
