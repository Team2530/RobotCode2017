#ifndef Tracker_H
#define Tracker_H
#include "WPILib.h"
#include "AHRS.h"
#include <Commands/Subsystem.h>

class Tracker : public Subsystem {
private:

	double* angle;
	Encoder* frontEncoder;
	Encoder* sideEncoder;
	AHRS* ahrs;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Tracker();
	void InitDefaultCommand();
	void GetPosition();
};

#endif  // Tracker_H
