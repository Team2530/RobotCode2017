/*
 * IntakeOn.h
 *
 *  Created on: Jan 27, 2017
 *      Author: Jason Mitchell
 */

#ifndef SRC_COMMANDS_INTAKEON_H_
#define SRC_COMMANDS_INTAKEON_H_

#include <Commands/Command.h>

class IntakeOn : public Command {
public:
	IntakeOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};




#endif /* SRC_COMMANDS_INTAKEON_H_ */
