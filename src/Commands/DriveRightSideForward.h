/*
 * DriveRightSideForward.h
 *
 *  Created on: Feb 11, 2017
 *      Author: Shadotiz
 */

#ifndef SRC_COMMANDS_DRIVERIGHTSIDEFORWARD_H_
#define SRC_COMMANDS_DRIVERIGHTSIDEFORWARD_H_

#include <Commands/Command.h>

class DriveRightSideForward : public Command {
public:
	DriveRightSideForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_DRIVERIGHTSIDEFORWARD_H_ */
