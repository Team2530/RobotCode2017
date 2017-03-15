#ifndef Tracker_H
#define Tracker_H
#include "OI.h"
#include "DriverStation.h"
#include <Encoder.h>
#include <PIDSource.h>
#include <PIDOutput.h>
#include <PIDController.h>

#include "DriveTrain.h"

#include <math.h>

#include "../Positions/Position.h"

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
		//std::printf("PIDWrite %f (@%p)\n", output, src);
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

	double frontLastMeasurement;
	double sideLastMeasurement;

	// These represent where we are on the field (X, Y)
	// and where we are facing.
	double goalPositionX;
	double goalPositionY;
	double currentPositionX; // Right
	double currentPositionY; // Forward
	double currentAngle; // angle in degrees, right is positive

	double angleAdjustment;

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
	std::shared_ptr<NetworkTable> SDtable;
	std::shared_ptr<ITable> DBtable;

public:
	Tracker();
	void InitDefaultCommand();
	void StartTracking(double initialX = 0, double initialY = 0, double initialAngle = 0);
	void GetPosition();
	// For controlling position
	// Initialize the PID controllers
	// Rotate while staying in place
	void RotateTo(double angle);
	void RotateBy(double deltaAngle);
	// Move while keeping heading
	void MoveToRel(double dx, double dy);
	void MoveToAbs(double x, double y);
	// Move right/forward relative to robot orientation
	void MoveRF(double right, double forward);
	// Set both position and rotation
	void Set(double x, double y, double angle);
	// Set based on a position that receives the current position
	// to update to the goal position.
	void MoveToPos(Position* pos);

	// Read PID controller output
	double GetPIDRotation();

	// Check if the robot is close to its goal
	bool PIDFinished();
	// Reset the PID Controllers
	void PIDReset();
	// Disable the PID loop when done
	void PIDDisable();

	double GetCurrentPositionX();
	double GetCurrentPositionY();
	double GetDistance(); // gets distance between current and goal positions
	double PIDGet(); // alias for GetDistance() for the PID feeding into power

	void UpdatePIDFromTable();

	// Call with Robot::drivetrain.get()
	// To move wheels towards goal position or rotation
	void Drive(DriveTrain* drivetrain);
};

#endif  // Tracker_H
