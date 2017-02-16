#ifndef AimCameratoLift_H
#define AimCameratoLift_H

#include <Commands/Command.h>

class AimCameratoLift : public Command {
public:
	AimCameratoLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AimCameratoLift_H
