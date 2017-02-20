#include "Dumper.h"
#include "ControllerConstants.h"


#include "../RobotMap.h"
//THIS IS A VERY ROUGH DRAFT~ it presumes motors, not pneumatics. Depending where mechanical goes,
//    things may need to change in order for it to work for pneumatics.
Dumper::Dumper() : Subsystem("DumperSubsystem") {
	dumperController = new frc::Jaguar(kDumperController);
	lowlimitswitch =new DigitalInput (ControllerConstants ::DIOPort:: kDIO4);
	highlimitswitch =new DigitalInput (ControllerConstants :: DIOPort ::kDIO5);
}

void Dumper::InitDefaultCommand() {
	//dumperDouble->Set(DoubleSolenoid::Value::kOff);
	//hatchDouble->Set(DoubleSolenoid::Value::kOff);

	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new Output());
}
bool Dumper::isDumperAtTop(){
return !highlimitswitch->Get();

}
bool Dumper::isDumperAtBottom(){
return !lowlimitswitch->Get();
}
void Dumper::Dump(){
	dumperController->Set(-1);
}
void Dumper::ResetDump(){
	dumperController->Set(0.30);
}
/*bool Dumper::FinishedDumping(){


	if (hatchBottom->Get()&&dumperTop->Get()){
		return false;
	}
	else{
		return true;
	}
}*/

/*bool Dumper::FinishedReseting(){
	if (hatchTop->Get()&&dumperBottom->Get()){
		return false;
	}
	else{
		return true;
	}

}*/
void Dumper::Stop(){
	dumperController->Set(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
