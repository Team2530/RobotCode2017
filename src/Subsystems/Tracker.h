#ifndef Tracker_H
#define Tracker_H
#include "WPILib.h"
#include "AHRS.h"
#include <Commands/Subsystem.h>
#include "../StartPositions.h"

class Tracker : public Subsystem {
private:

	double* angle;
	Encoder* frontEncoder;
	Encoder* sideEncoder;
	AHRS* ahrs;
	double xValue;//can be set depending where are on map
	double yValue;//^^

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// These represent where we are on the field (X, Y)
	// and where we are facing.
	double currentPositionX;
	double currentPositionY;
	double currentAngle;

public:
	Tracker();
	void InitDefaultCommand();
	void StartTracking(StartPosition position, StartTeam team);
	void GetPosition();
	double GetOriginalPositionX(StartPosition position, StartTeam team);

};

#endif  // Tracker_H
