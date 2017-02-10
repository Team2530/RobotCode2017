#ifndef Dump_H
#define Dump_H
#include "WPILib.h"
//#include "../CommandBase.h"
#include <Commands\Command.h>

class Dump : public Command {
public:
	Dump();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Dump_H
