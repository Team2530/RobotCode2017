#ifndef Dumper_H
#define Dumper_H
#include "WPILib.h"

#include <Commands/Subsystem.h>

class Dumper : public Subsystem {
private:
	static constexpr int kHatchController = 6; //SET TO ACTUAL
	static constexpr int kDumperController = 6; //SET TO ACTUAL

	//Victor SP stuff in case hardware decideds to change things again
	//VictorSP* hatchController;
	//VictorSP* dumperController;
	//DigitalInput* hatchBottom;
	//DigitalInput* hatchTop;
	//DigitalInput* dumperBottom;
	//DigitalInput* dumperTop;

	DoubleSolenoid* hatchDouble;
	DoubleSolenoid* dumperDouble;


	DigitalInput* hatchBottom;
	DigitalInput* hatchTop;
	DigitalInput* dumperBottom;
	DigitalInput* dumperTop;
	
	Encoder* frontEncoder;
	Encoder* sideEncoder;
	

	double kHatchSpeedCap = 0.2; //SET TO ACTUAL
	double kDumperSpeedCap = 0.7; //SET TO ACTUAL

public:
	Dumper();
	void InitDefaultCommand();
	void Dump();
	void ResetDump();
	/*void FinishedDumping;
	void FinishedReseting;*/
	void Stop();
};

#endif  // Dumper_H
