#include "Lifter.h"
#include "../RobotMap.h"
#include "WPILib.h"

Lifter::Lifter() : Subsystem("LifterSubsystem") {
	jaguar = new Jaguar (kliftermotor);

}

void Lifter::InitDefaultCommand() {


}

void Lifter::Stop(){
	jaguar->SetSpeed(0.0);

}

void Lifter::Fast(){
	jaguar->SetSpeed(1);

}

void Lifter::Slow(){
	jaguar->SetSpeed(0.5);
}

