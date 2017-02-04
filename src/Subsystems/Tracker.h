#ifndef Tracker_H
#define Tracker_H
#include "WPILib.h"
#include "AHRS.h"
#include <Commands/Subsystem.h>

class Tracker : public Subsystem {
private:
	float* xAccel;
	float* yAccel;
	double* angle;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Encoder *frontEncoder;
	Encoder *sideEncoder;
	AHRS *ahrs;

	double kFrontDistancePerPulse= -1*3.14159*8/339;//check
	double kSideDistancePerPulse= 3.14159*8/230;//check
public:
	Tracker();
	void InitDefaultCommand();
	void GetPosition();
};

#endif  // Tracker_H
