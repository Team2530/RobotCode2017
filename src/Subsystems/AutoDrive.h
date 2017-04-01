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

class PIDAngleSource : public frc::PIDSource {
public:
	double PIDGet() override;
};

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

class AutoDrive : public Subsystem, frc::PIDSource {
private:
	double goalPositionX;
	double goalPositionY;

	// Heading lock variables
	bool headingLockEnabled;

	// Outputs from PID Controllers
	double pidr;
	double power;
	double MAX_POW;

	// PID helper classes for the PID Controllers
	// (The other source is this class itself
	// since it needs to calculate the distance)
	PIDAngleSource pidrs; // &this->currentAngle
	PIDDoubleOutput pidro; // &this->pidr
	PIDDoubleOutput pidpo; // &this->power

	// Power PID Controller, goes from this class's
	// distance calculation to the power member
	frc::PIDController pidpc;
	// Rotation PID Controller, using pidrs and pidro
	// to go from currentAngle to pidr
	frc::PIDController pidrc;

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

	double PIDGet(); // alias for GetDistance() for the PID feeding into power

	void UpdatePIDFromTable();
	void SetMaxPower(double pow = 0.75);

	// Call with Robot::drivetrain.get()
	// To move wheels towards goal position or rotation
	void Drive(DriveTrain* drivetrain);
};

#endif  // AutoDrive_H
