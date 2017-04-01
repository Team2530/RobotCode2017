#ifndef CameraServo_H
#define CameraServo_H
#include "WPILib.h"

class CameraServo : public Subsystem {
private:
	Servo *servo;
public:
	CameraServo();
	void InitDefaultCommand();
	void AimTaco ();
	void AimLift ();
	void AimFrontTaco ();
};

#endif  // CameraServo_H
