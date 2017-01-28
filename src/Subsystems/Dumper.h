#ifndef Dumper_H
#define Dumper_H
#include "WPILib.h"

#include <Commands/Subsystem.h>

class Dumper : public Subsystem {
private:
	static constexpr int kHatchController = 0; //SET TO ACTUAL
	static constexpr int kDumperController = 0; //SET TO ACTUAL


	VictorSP* hatchController;
	VictorSP* dumperController;

	DigitalInput* hatchBottom;
	DigitalInput* hatchTop;
	DigitalInput* dumperBottom;
	DigitalInput* dumperTop;

	double kHatchSpeedCap = 0.2; //SET TO ACTUAL
	double kDumperSpeedCap = 0.7; //SET TO ACTUAL

public:
	Dumper();
	void InitDefaultCommand();
	void Dump();
	void Reset();
	bool FinishedDumping();
	bool FinishedReseting();
	void Stop();
};

#endif  // Dumper_H
