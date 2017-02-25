#ifndef MoveRF_H
#define MoveRF_H

#include <Commands/Command.h>

class MoveRF : public Command {
private:
	double r;
	double f;
public:
	MoveRF(double right, double forward);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveRF_H
