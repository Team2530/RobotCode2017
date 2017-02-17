#ifndef MecanumDriveFieldOriented_H
#define MecanumDriveFieldOriented_H

#include "../CommandBase.h"
#include "AHRS.h"
#include "WPILib.h"

class MecanumDriveFieldOriented : public CommandBase {
public:
	MecanumDriveFieldOriented();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double ResetYawAngle();
private:

};

#endif  // MecanumDriveFieldOriented_H
