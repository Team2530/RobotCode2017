#include "WaitForVisionAndMove.h"

#include "../Commands/LEDControl.h"
#include "../Commands/AimCameratoTaco.h"
#include "../Commands/DriveToFieldPosition.h"
#include "../Commands/DriveToPosition.h"
#include "../Commands/MoveBasedOnVision.h"
#include "../Positions/Absolute.h"
#include "../Positions/RobotRelative.h"
#include "../FieldPositions/FieldPositionToRotateTo.h"
#include "../FieldPositions/GearFieldPosition.h"

WaitForVisionAndMove::WaitForVisionAndMove() {
	AddSequential(new LEDControl(true));
	AddSequential(new AimCameratoTaco());
	//AddSequential(new MoveBasedOnVision(36, gear));
}
