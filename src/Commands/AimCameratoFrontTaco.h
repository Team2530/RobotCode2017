#ifndef AimCameratoFrontTaco_H
#define AimCameratoFrontTaco_H

#include <Commands/Command.h>

class AimCameratoFrontTaco : public Command {
public:
	AimCameratoFrontTaco();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AimCameratoFrontTaco_H
