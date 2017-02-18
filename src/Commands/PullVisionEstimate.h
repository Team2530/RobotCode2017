#ifndef PullVisionEstimate_H
#define PullVisionEstimate_H

#include <Commands/Command.h>

class PullVisionEstimate : public frc::Command {
public:
	PullVisionEstimate();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PullVisionEstimate_H
