#ifndef Tracker_H
#define Tracker_H
#include "WPILib.h"
#include "OI.h"
#include <Commands/Subsystem.h>
#include "../StartPositions.h"
#include "DriverStation.h"
#include <Encoder.h>
#include <PIDSource.h>
#include <PIDOutput.h>
#include <PIDController.h>

#include "DriveTrain.h"

#include <math.h>

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

class Tracker : public frc::Subsystem, frc::PIDSource {
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
	double goalPositionX;
	double goalPositionY;
	double currentPositionX; // Right
	double currentPositionY; // Forward
	double currentAngle; // angle in degrees, right is positive??

	double pidr;
	double power;

	PIDDoubleSource pidrs;
	PIDDoubleOutput pidro;
	PIDDoubleOutput pidpo;

	frc::PIDController pidpc;
	frc::PIDController pidrc;
	std::shared_ptr<NetworkTable> table;

public:
	Tracker();
	void InitDefaultCommand();
	void StartTracking();
	void GetPosition();
	// For controlling position
	// Initialize the PID controllers
	// Rotate while staying in place
	void RotateTo(double angle);
	void RotateBy(double deltaAngle);
	// Move while keeping heading
	void MoveToRel(double forward, double right);
	void MoveToAbs(double x, double y);

	// Read PID controller output
	double GetPIDRotation();

	bool PIDFinished();
	void PIDReset();

	double GetCurrentPositionX();
	double GetCurrentPositionY();
	double GetDistance();
	double PIDGet();

	void Drive(DriveTrain* drivetrain);
};

#endif  // Tracker_H
