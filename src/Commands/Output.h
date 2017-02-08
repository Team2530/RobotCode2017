#ifndef Output_H
#define Output_H
#include "WPILib.h"
//#include "../CommandBase.h"
#include <Commands\Command.h>

class Output : public Command {
public:
	Output();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Output_H
