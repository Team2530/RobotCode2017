#ifndef Tracker_H
#define Tracker_H

#include "OI.h"
#include "DriverStation.h"
#include <Encoder.h>

class Tracker : public frc::Subsystem {
private:
	frc::Encoder* frontEncoder;
	frc::Encoder* sideEncoder;
	AHRS* ahrs;

	double frontLastMeasurement;
	double sideLastMeasurement;

	// These represent where we are on the field (X, Y)
	// and where we are facing.
	double currentPositionX; // Right
	double currentPositionY; // Forward
	double currentAngle; // angle in degrees, right is positive
	double angleAdjustment; // starting angle when AHRS is reset

	std::shared_ptr<NetworkTable> table;

public:

	Tracker();
	void InitDefaultCommand();
	void StartTracking(double initialX = 0, double initialY = 0, double initialAngle = 0);
	void UpdatePosition();

	double GetCurrentPositionX();
	double GetCurrentPositionY();
	double GetCurrentAngle();
};

#endif  // Tracker_H
