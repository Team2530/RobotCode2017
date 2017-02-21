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
	frc::Encoder* frontEncoder;
	frc::Encoder* sideEncoder;
	AHRS* ahrs;

	// These represent where we are on the field (X, Y)
	// and where we are facing.
	double goalPositionX;
	double goalPositionY;
	double currentPositionX; // Right
	double currentPositionY; // Forward
	double currentAngle; // angle in degrees, right is positive??

	// Outputs from PID Controllers
	double pidr;
	double power;

	// PID helper classes for the PID Controllers
	// (The other source is this class itself
	// since it needs to calculate the distance)
	PIDDoubleSource pidrs; // &this->currentAngle
	PIDDoubleOutput pidro; // &this->pidr
	PIDDoubleOutput pidpo; // &this->power

	// Power PID Controller, goes from this class's
	// distance calculation to the power member
	frc::PIDController pidpc;
	// Rotation PID Controller, using pidrs and pidro
	// to go from currentAngle to pidr
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

	// Check if the robot is close to its goal
	bool PIDFinished();
	// Reset the PID Controllers
	void PIDReset();

	double GetCurrentPositionX();
	double GetCurrentPositionY();
	double GetDistance(); // gets distance between current and goal positions
	double PIDGet(); // alias for GetDistance() for the PID feeding into power

	// Call with Robot::drivetrain.get()
	// To move wheels towards goal position or rotation
	void Drive(DriveTrain* drivetrain);
};

#endif  // Tracker_H
