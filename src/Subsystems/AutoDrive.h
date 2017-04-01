#ifndef AutoDrive_H
#define AutoDrive_H

#include "OI.h"
#include "DriverStation.h"
#include <Commands/Subsystem.h>
#include <PIDSource.h>
#include <PIDOutput.h>
#include <PIDController.h>

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

public:
	AutoDrive();
	void InitDefaultCommand();
	// Set both position and rotation
	void Set(double x, double y, double angle);
	// Set based on a Position that receives the current position
	// to update to the goal position.
	void MoveToPos(Position* pos);

	double GetDistance(); // gets distance between current and goal positions

	// Read PID controller output
	double GetPIDRotation();
	// Pass in a deadbanded twist value
	// Enable heading lock and return PID value if twist == 0
	// Otherwise, return twist back
	void EnableHeadingLock(bool enabled);

	// Check if the robot is close to its goal
	bool PIDFinished();
	// Reset the PID Controllers
	void PIDReset();
	// Disable the PID loop when done
	void PIDDisable();

	void UpdatePIDFromTable();
	void SetMaxPower(double pow = 0.75);

	// Call with Robot::drivetrain.get()
	// To move wheels towards goal position or rotation
	void Drive(DriveTrain* drivetrain);

	double GetCoordAngleRad();
	double GetCoordAngleDeg();
	double GetGoalPositionX();
	double GetGoalPositionY();
};

#endif  // AutoDrive_H
