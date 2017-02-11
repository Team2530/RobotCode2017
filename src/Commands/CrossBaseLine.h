#ifndef CrossBaseLine_H
#define CrossBaseLine_H

#include <Commands/Command.h>

class CrossBaseLine : public Command {
public:
	CrossBaseLine();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CrossBaseLine_H
