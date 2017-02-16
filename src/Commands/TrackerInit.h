#ifndef TrackerInit_H
#define TrackerInit_H
#include "DriverStation.h"
#include <Commands/Command.h>
#include "../StartPositions.h"

class TrackerInit : public Command {
public:
	TrackerInit(StartPosition position, frc::DriverStation::Alliance team);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	StartPosition position;
	frc::DriverStation::Alliance team;
};


#endif  // TrackerInit_H
