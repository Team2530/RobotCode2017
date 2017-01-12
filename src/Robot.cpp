#include "WPILib.h"

#include "DriveTrain.h"

/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive
 * class.
 */
class Robot: public frc::SampleRobot {
public:
	Robot() {
		driveTrain = new DriveTrain();
	}

	/**
	 * Runs the motors with Mecanum drive.
	 */
	void OperatorControl() override {
		driveTrain->SetSafetyEnabled(false);
		while (IsOperatorControl() && IsEnabled()) {
			driveTrain->update();

			Wait(0.005); // wait 5ms to avoid hogging CPU cycles
		}
	}

private:
	DriveTrain* driveTrain;
};

START_ROBOT_CLASS(Robot)
