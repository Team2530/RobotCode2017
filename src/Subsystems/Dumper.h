#ifndef Dumper_H
#define Dumper_H
#include "WPILib.h"

#include <Commands/Subsystem.h>

class Dumper : public Subsystem {
private:
	static constexpr int kDumperController = 6; //SET TO ACTUAL

	//Victor SP stuff in case hardware decideds to change things again
	//VictorSP* hatchController;
	//VictorSP* dumperController;
	//DigitalInput* hatchBottom;
	//DigitalInput* hatchTop;
	//DigitalInput* dumperBottom;
	//DigitalInput* dumperTop;

	frc::Jaguar* dumperController;

	double kDumperSpeedCap = -0.5; //SET TO ACTUAL

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
