/*
 * DeliverGear.h
 *
 *  Created on: Feb 2, 2017
 *      Author: Shadotiz
 */

#ifndef SRC_COMMANDS_DELIVERGEAR_H_
#define SRC_COMMANDS_DELIVERGEAR_H_
#include "WPILib.h"

//#include "../CommandBase.h"

#include <Commands\Command.h>

class DeliverGear : public Command {
public:
	DeliverGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_DELIVERGEAR_H_ */
