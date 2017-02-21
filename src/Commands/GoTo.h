#ifndef GoTo_H
#define GoTo_H

#include <Commands/Command.h>

class GoTo : public frc::Command {
private:
	double goalX;
	double goalY;
public:
	GoTo(double x, double y);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GoTo_H
