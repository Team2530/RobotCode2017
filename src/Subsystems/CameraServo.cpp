#include "CameraServo.h"
#include "../RobotMap.h"
#include "ControllerConstants.h"
CameraServo::CameraServo() : Subsystem("CameraServoSubsystem") {
servo= new Servo (ControllerConstants :: PWMPort :: kPWM5) ;

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
