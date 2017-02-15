#ifndef OrientRobot_H
#define OrientRobot_H

<<<<<<< HEAD
#include "Commands/Command.h"
=======
>>>>>>> master
#include <AHRS.h>

class OrientRobot : public Command{
public:
	OrientRobot(double TargetAngle);
	OrientRobot(double x, double y);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double TurnAngleDetermination(double OffsetAngle);//How far robot needs to turn to correct course; finds that
	double TurningSpeedDetermination(double OffsetAngle);
private:
	double TurnAngle;//Is the degree by which the robot needs to turn to correct itself
	double Angle;
};


#endif  // OrientRobot_H
