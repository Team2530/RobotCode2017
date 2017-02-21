#include "Lifter.h"
#include "../RobotMap.h"
#include "WPILib.h"

Lifter::Lifter() : Subsystem("LifterSubsystem") {
	lifterMotor = new VictorSP (kliftermotor);

}

void Lifter::InitDefaultCommand() {


}

void Lifter::Stop(){
	lifterMotor->SetSpeed(0.0);

}

void Lifter::Fast(){
	lifterMotor->SetSpeed(1);

}

void Lifter::Slow(){
	lifterMotor->SetSpeed(0.5);
}

