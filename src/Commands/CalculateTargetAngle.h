#ifndef CalculateTargetAngle_H
#define CalculateTargetAngle_H

#include "Commands/Command.h"
// replace with FieldLocation
class CalculateTargetAngle : public Command {
public:
	CalculateTargetAngle(double *x, double *y, double *angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

double *xpointer;
double *ypointer;
double *anglepointer;

};

#endif  // CalculateTargetAngle_H
