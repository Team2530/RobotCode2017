#ifndef GetFieldPosition_H
#define GetFieldPosition_H

#include <Commands/Command.h>


class GetFieldPosition : public Command {
public:
	GetFieldPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GetFieldPosition_H
