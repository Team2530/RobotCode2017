#ifndef AimCameratoTaco_H
#define AimCameratoTaco_H

#include <Commands/Command.h>

class AimCameratoTaco : public Command {
public:
	AimCameratoTaco();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AimCameratoTaco_H
