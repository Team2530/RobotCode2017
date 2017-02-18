#include "Lifter.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include "AHRS.h"
Lifter::Lifter() : Subsystem("ExampleSubsystem") {
	jaguar=new Jaguar (kliftermotor=5);
	Requires(Robot::drivetrain->Drive)

}

void Lifter::InitDefaultCommand() {


}

void Lifter::Stop(){

}

