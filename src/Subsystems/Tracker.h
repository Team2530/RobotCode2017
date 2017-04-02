#ifndef Tracker_H
#define Tracker_H

#include "OI.h"

class Tracker : public frc::Subsystem {
private:
	frc::Encoder* frontEncoder;
	frc::Encoder* sideEncoder;
	AHRS* ahrs;

	double frontLastMeasurement;
	double sideLastMeasurement;

	// These represent where the robot is on the field (X, Y)
	// and where it faced at the start of the match.
	// (The current angle is no longer kept in a variable,
	// use Tracker::GetCurrentAngle for that.)
	double currentPositionX; // Right
	double currentPositionY; // Forward
	double angleAdjustment; // starting angle when AHRS is reset

	std::shared_ptr<NetworkTable> table;

public:

	Tracker();
	void InitDefaultCommand();
	void StartTracking(double initialX = 0, double initialY = 0, double initialAngle = 0);
	void UpdatePosition();

	double GetCurrentPositionX();
	double GetCurrentPositionY();
	// Get the adjusted angle on the field, in the range +/-180
	// where positive is rotated right/clockwise and 0 degrees points
	// straight forward on the field (i.e. away from the driver)
	double GetCurrentAngle();
};

#endif  // Tracker_H
