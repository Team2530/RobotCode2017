#ifndef MecanumDriveFieldOriented_H
#define MecanumDriveFieldOriented_H

#include "Commands/Command.h"
#include "AHRS.h"
#include "WPILib.h"

class MecanumDriveFieldOriented : public Command {
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

