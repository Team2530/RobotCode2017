#ifndef TrackerInit_H
#define TrackerInit_H

#include <Commands/Command.h>
#include "../StartPositions.h"

class TrackerInit : public Command {
public:
	TrackerInit(StartPosition position, StartTeam team);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	StartPosition position;
	StartTeam team;
};


#endif  // TrackerInit_H
