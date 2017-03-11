#ifndef MoveBasedOnVision_H
#define MoveBasedOnVision_H

#include <Commands/Command.h>
// replace with FieldLocation??

class MoveBasedOnVision : public frc::Command {
private:
	double goal;
	double lock;
public:
	MoveBasedOnVision(double distance = 36, double angle = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveBasedOnVision_H
