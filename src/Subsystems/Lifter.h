#ifndef Lifter_H
#define Lifter_H
#include <Commands/Subsystem.h>
#include <VictorSP.h>


class Lifter : public Subsystem {
private:
	int kliftermotor = 7;
	VictorSP *lifterMotor;


public:
	Lifter();
	void InitDefaultCommand();
	void Fast();
	void Slow();
	void Stop();
	void Reverse();




};

#endif  // Lifter_H
