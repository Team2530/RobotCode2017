#include "Dumper.h"
#include "ControllerConstants.h"


#include "../RobotMap.h"
//THIS IS A VERY ROUGH DRAFT~ it presumes motors, not pneumatics. Depending where mechanical goes,
//    things may need to change in order for it to work for pneumatics.
Dumper::Dumper() : Subsystem("DumperSubsystem") {
	dumperController = new frc::Jaguar(kDumperController);
}

void Dumper::InitDefaultCommand() {
	//dumperDouble->Set(DoubleSolenoid::Value::kOff);
	//hatchDouble->Set(DoubleSolenoid::Value::kOff);

	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new Output());
}
void Dumper::Dump(){

	dumperDouble->Set(DoubleSolenoid::Value::kForward);
	hatchDouble->Set(DoubleSolenoid::Value::kForward);

	/*if (hatchBottom->Get()){
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
*/
}
void Dumper::ResetDump(){

	dumperDouble->Set(DoubleSolenoid::Value::kReverse);
	hatchDouble->Set(DoubleSolenoid::Value::kReverse);

	/*if (hatchTop->Get()){
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

*/
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
