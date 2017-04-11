#ifndef AutoDrive_H
#define AutoDrive_H

#include "OI.h"

#include "DriveTrain.h"

#include <math.h>

#include "../Positions/Position.h"

// A PIDSource to track the current angle from Tracker
class PIDAngleSource : public frc::PIDSource {
public:
	double PIDGet() override;
};

// A PIDSource to track displacement along the path
class PIDParallelSource : public frc::PIDSource {
public:
	double PIDGet() override;
};

// A PIDSource to track drift across the path
class PIDPerpendicularSource : public frc::PIDSource {
public:
	double PIDGet() override;
};

// Unused: returns value of a double pointer
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

// Sets value to a double pointer
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

class AutoDrive : public Subsystem {
private:
	double goalPositionX;
	double goalPositionY;

	// Heading lock variables
	bool headingLockEnabled;

	// The angle from start position to goal position, for PID control
	double pathAngleRad;

	// How fast to limit the PID controller output to
	double MAX_POW;

	// Corrections from PID Controllers
	double angleC;
	double parallelC;
	double perpendicularC;

	// PID helper classes for the PID Controllers
	// Sources
	PIDAngleSource angleS;
	PIDParallelSource parallelS;
	PIDPerpendicularSource perpendicularS;
	// Outputs
	PIDDoubleOutput angleO; // -> &this->angleC
	PIDDoubleOutput parallelO; // -> &this->parallelC
	PIDDoubleOutput perpendicularO; // -> &this->perpendicularC

	frc::PIDController anglePID;
	frc::PIDController parallelPID;
	frc::PIDController perpendicularPID;

	std::shared_ptr<NetworkTable> SDtable;
	std::shared_ptr<ITable> DBtable;

	int countStopsInRow;

public:
	AutoDrive();
	void InitDefaultCommand();

	// Set a goal position based on a Position.
	// Position::updatePosition will receive
	// the current position to update to the goal position.
	void MoveToPos(Position* pos);
	// Set both a field position and a rotation to achieve
	void Set(double x, double y, double angle);
	// Set a speed to move at (maximum).
	// Default: 0.75 (Miracle Max), 0.3 (Zomberdinck)
	void SetMaxPower(double pow = 0.75);

	// Call with Robot::drivetrain.get() each iteration
	// to move wheels towards goal position or rotation
	void Drive(DriveTrain* drivetrain);

	// Check if the robot is close enough to its goal
	bool PIDFinished();
	// Disable and reset the PID controllers when done
	void PIDDisable();

	// Enable or disable the heading lock
	// (This will set the PID to track the current angle)
	void EnableHeadingLock(bool enabled);
	// Read PID controller output for heading lock
	double GetPIDRotation();

	// Update PIDs using values from SmartDashboard's "Basic" tab
	void UpdatePIDFromTable();

	// Get the coordinates of the goal
	double GetGoalPositionX();
	double GetGoalPositionY();
	double GetGoalAngle(); // degrees
	// Unused: Get distance between current and goal positions
	double GetDistance();
	// Get the rotation of the coordinate system for the PIDs
	// from the default field coordinate system
	// (y = away from driver, x = positive to the right)
	double GetCoordAngleRad();
	double GetCoordAngleDeg();
};

#endif  // AutoDrive_H
