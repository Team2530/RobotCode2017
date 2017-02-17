#ifndef Lifter_H
#define Lifter_H
#include <Commands/Subsystem.h>
#include <Jaguar.h>
class Lifter : public Subsystem {
private:
	int kliftermotor=5;
	Jaguar *jaguar;


public:
	Lifter();
	void InitDefaultCommand();
};

#endif  // Lifter_H
