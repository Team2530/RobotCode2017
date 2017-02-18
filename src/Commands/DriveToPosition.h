#ifndef DriveToPosition_H
#define DriveToPosition_H

#include <Commands/Command.h>

class DriveToPosition : public frc::Command {
public:
	DriveToPosition(double *x, double *y);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
double *xposition;
double *yposition;
};

#endif  // DriveToPosition_H
