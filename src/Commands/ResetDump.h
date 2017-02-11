#ifndef ResetDump_H
#define ResetDump_H

#include <Commands/Command.h>


class ResetDump : public Command {
public:
	ResetDump();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetDump_H
