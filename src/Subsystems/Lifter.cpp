#include "Lifter.h"
#include "../RobotMap.h"
#include "WPILib.h"

Lifter::Lifter() : Subsystem("ExampleSubsystem") {
	jaguar = new Jaguar (kliftermotor);

}

void Lifter::InitDefaultCommand() {


}

void Lifter::Stop(){
	jaguar->SetSpeed(0.0);

}

void Lifter::Go(){
	jaguar->SetSpeed(0.7);

}

