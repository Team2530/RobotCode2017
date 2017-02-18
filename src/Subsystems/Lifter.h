#ifndef Lifter_H
#define Lifter_H
#include <Commands/Subsystem.h>
#include <Jaguar.h>
#include "WPILib.h"
#include "AHRS.h"
class Lifter : public Subsystem {
private:
	int kliftermotor=5;
	Jaguar *jaguar;


public:
	Lifter();
	void InitDefaultCommand();
	void Execute();
	void Initialize();
	void Interrupted();
	void Stop();

};

#endif  // Lifter_H
