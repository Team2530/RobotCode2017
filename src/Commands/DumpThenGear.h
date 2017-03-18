#ifndef DumpThenGear_H
#define DumpThenGear_H
#include "Commands/Command.h"
#include "Commands/CommandGroupEntry.h"
#include "../StartPositions.h"


#include <Commands/CommandGroup.h>

class DumpThenGear : public CommandGroup {
public:
	DumpThenGear();
		void Initialize();
		void Execute();
		bool IsFinished();
		void End();
		void Interrupted();
	};



#endif  // DumpThenGear_H