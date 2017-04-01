#include "CameraServo.h"
#include "../RobotMap.h"
#include "ControllerConstants.h"
CameraServo::CameraServo() : Subsystem("CameraServoSubsystem") {
servo= new Servo (ControllerConstants :: PWMPort :: kPWM5) ;

}

void CameraServo::InitDefaultCommand() {

}
void CameraServo:: AimTaco () {
	servo-> SetAngle (130);
}
void CameraServo:: AimLift (){
	servo-> SetAngle (145);
}

void CameraServo:: AimFrontTaco () {
	servo-> SetAngle (160);     									//This angle needs to be tested, it currently is a guess.
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
