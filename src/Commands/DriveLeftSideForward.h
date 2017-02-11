/*
 * DriveLeftSideForward.h
 *
 *  Created on: Feb 11, 2017
 *      Author: Shadotiz
 */

#ifndef SRC_COMMANDS_DRIVELEFTSIDEFORWARD_H_
#define SRC_COMMANDS_DRIVELEFTSIDEFORWARD_H_

#include <Commands/Command.h>

class DriveLeftSideForward : public Command {
public:
	DriveLeftSideForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_DRIVELEFTSIDEFORWARD_H_ */
