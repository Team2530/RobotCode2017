#ifndef Lifter_H
#define Lifter_H
#include <Commands/Subsystem.h>
#include <Jaguar.h>


class Lifter : public Subsystem {
private:
	int kliftermotor = 7;
	Jaguar *jaguar;


public:
	Lifter();
	void InitDefaultCommand();
	void Fast();
	void Slow();
	void Stop();

};

#endif  // Lifter_H
