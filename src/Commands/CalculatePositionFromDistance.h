#ifndef CalculatePositionFromDistance_H
#define CalculatePositionFromDistance_H

#include "Commands/Command.h"

class CalculatePositionFromDistance : public Command {
public:
	//CPFD is short for Calculate Position From Distance
	double CPFDCoordinatesX;
	double CPFDCoordinatesY;
	double *angleCPFD;
	double *distanceForwardToGoCPFD;
	double *currentPositionXCPFD; // Right
	double *currentPositionYCPFD; // Forward
	CalculatePositionFromDistance(double *angle, double *distanceForwardToGo, double *currentPositionX, double *currentPositionY);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CalculatePositionFromDistance_H
