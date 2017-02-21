#ifndef ResetTracker_H
#define ResetTracker_H

#include <Commands/Command.h>

class ResetTracker : public frc::Command {
public:
	ResetTracker();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetTracker_H
