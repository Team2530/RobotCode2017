#ifndef CameraServo_H
#define CameraServo_H
#include "WPILib.h"
#include "../Orientation.h"

class CameraServo : public Subsystem {
private:
	Servo *servo;
public:
	CameraServo();
	void InitDefaultCommand();
	void AimTaco ();
	void AimLift ();
	void AimFrontTaco ();
	Orientation facing;
};

#endif  // CameraServo_H
