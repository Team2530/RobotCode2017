#ifndef MoveBy_H
#define MoveBy_H

#include <Commands/Command.h>

class MoveBy : public frc::Command {
private:
	double goalX;
	double goalY;
public:
	MoveBy(double x, double y);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveBy_H
