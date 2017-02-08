#include "Intake.h"
#include "../RobotMap.h"

#include "../Commands/MecanumDriveWithJoystick.h"

Intake::Intake() : Subsystem("IntakeSubsystem") {
	intakeMotor = new VictorSP(kIntakeChannel);
}
void Intake::InitDefaultCommand() {
}
void Intake::IntakeOn(){
	intakeMotor->Set(1);
}
void Intake::IntakeOff(){
	intakeMotor->Set(0.0);
}
void Intake::IntakeInvert(){
	intakeMotor->Set(-1);
}
