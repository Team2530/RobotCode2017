#include "Dumper.h"
#include "ControllerConstants.h"
#include "../RobotMap.h"
//THIS IS A VERY ROUGH DRAFT~ it presumes motors, not pneumatics. Depending where mechanical goes,
//    things may need to change in order for it to work for pneumatics.
Dumper::Dumper() : Subsystem("DumperSubsystem") {
	hatchController= new VictorSP(kHatchController);
	dumperController = new VictorSP(kDumperController);
	hatchTop= new DigitalInput(ControllerConstants::DIOPort::kDIO6);//setReal
	hatchBottom= new DigitalInput(ControllerConstants::DIOPort::kDIO7);//setReal
	dumperTop= new DigitalInput(ControllerConstants::DIOPort::kDIO8);//setReal
	dumperBottom= new DigitalInput(ControllerConstants::DIOPort::kDIO9);//setReal
}

void Dumper::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new Output());
}
void Dumper::Dump(){
	if (hatchBottom->Get()){
		hatchController->Set(kHatchSpeedCap);
	}
	else{
		hatchController->Set(0);
	}
	if (dumperTop->Get()){
		dumperController->Set(kDumperSpeedCap);
	}
	else{
		dumperController->Set(0);
	}
	//open hatch
	//dump content
}
void Dumper::Reset(){
	if (hatchTop->Get()){
		hatchController->Set(-kHatchSpeedCap);
	}
	else{
		hatchController->Set(0);
	}
	if (dumperBottom->Get()){
		dumperController->Set(-kDumperSpeedCap);
	}
	else{
		dumperController->Set(0);
	}
	//close hatch
	//lower dumper

}
bool Dumper::FinishedDumping(){
	if (hatchBottom->Get()&&dumperTop->Get()){
		return false;
	}
	else{
		return true;
	}
}
bool Dumper::FinishedReseting(){
	if (hatchTop->Get()&&dumperBottom->Get()){
		return false;
	}
	else{
		return true;
	}
}
void Dumper::Stop(){
	hatchController->Set(0);
	dumperController->Set(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
