#include "CameraServo.h"
#include "../RobotMap.h"

CameraServo::CameraServo() : Subsystem("ExampleSubsystem") {
servo= new Servo (ControllerConstants :: PWMPort :: kPWM8) ;

}

void CameraServo::InitDefaultCommand() {

}
void CameraServo:: AimTaco () {
	servo-> SetAngle (0);
}
void CameraServo:: AimLift (){
	servo-> SetAngle (90);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
