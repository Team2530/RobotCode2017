#ifndef CameraServo_H
#define CameraServo_H
#include "WPILib.h"
#include <Commands/Subsystem.h>

class CameraServo : public Subsystem {
private:
	Servo *servo;
public:
	CameraServo();
	void InitDefaultCommand();
	void AimTaco ();
	void AimLift ();
};

#endif  // CameraServo_H
