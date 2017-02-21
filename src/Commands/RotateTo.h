#ifndef RotateTo_H
#define RotateTo_H

#include <Commands/Command.h>

class RotateTo : public frc::Command {
private:
	double goal;
public:
	RotateTo(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RotateTo_H
