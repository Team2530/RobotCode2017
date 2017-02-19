#ifndef DriveLeft_H
#define DriveLeft_H

#include <Commands/Command.h>

class DriveLeft : public frc::Command {
public:
  DriveLeft();
  void Initialize();
  void Execute();
  bool IsFinished();
  void End();
  void Interrupted();
};

#endif  // DriveLeft_H
