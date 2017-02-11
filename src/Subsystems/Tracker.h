#ifndef Tracker_H
#define Tracker_H
#include "WPILib.h"
#include "AHRS.h"
#include <Commands/Subsystem.h>
#include "../StartPositions.h"
#include <Encoder.h>
#include <PIDSource.h>
#include <PIDOutput.h>
#include <PIDController.h>

class Tracker;
class PIDDoubleSource : public frc::PIDSource {
public:
	PIDDoubleSource(double* source) {
		src = source;
	}
	double PIDGet() {
		return *src;
	}
private:
	double* src;
};
class PIDDoubleOutput : public frc::PIDOutput {
public:
	PIDDoubleOutput(double* source) {
		src = source;
	}
	void PIDWrite(double output) {
		*src = output;
	}
private:
	double* src;
};

class Tracker : public frc::Subsystem {
private:

	double* angle;
	frc::Encoder* frontEncoder;
	frc::Encoder* sideEncoder;
	AHRS* ahrs;
	double xValue;//can be set depending where are on map
	double yValue;//^^

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// These represent where we are on the field (X, Y)
	// and where we are facing.
	double currentPositionX; // Right
	double currentPositionY; // Forward
	double currentAngle; // angle in degrees, right is positive??

	double pidx;
	double pidy;
	double pidr;

	PIDDoubleSource pidxs;
	PIDDoubleSource pidys;
	PIDDoubleSource pidrs;
	PIDDoubleOutput pidxo;
	PIDDoubleOutput pidyo;
	PIDDoubleOutput pidro;

	frc::PIDController pidxc;
	frc::PIDController pidyc;
	frc::PIDController pidrc;

public:
	Tracker();
	void InitDefaultCommand();
	void StartTracking(StartPosition position, StartTeam team);
	void GetPosition();
	double GetOriginalPositionX(StartPosition position, StartTeam team);

	// For controlling position
	// Initialize the PID controllers
	// Rotate while staying in place
	void RotateTo(double angle);
	void RotateBy(double deltaAngle);
	// Move while keeping heading
	void MoveToRel(double forward, double right);
	void MoveToAbs(double x, double y);

	// Read PID controller output
	double GetPIDX();
	double GetPIDY();
	double GetPIDRotation();

	// And as oriented by the robot
	double GetPIDBackward();
	double GetPIDRight();
};

#endif  // Tracker_H
