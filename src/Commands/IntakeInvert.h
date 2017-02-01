/*
 * IntakeInvert.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Jason Mitchell
 */

#ifndef SRC_COMMANDS_INTAKEINVERT_H_
#define SRC_COMMANDS_INTAKEINVERT_H_

#include <Commands/Command.h>

class IntakeInvert : public Command {
public:
	IntakeInvert();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};





#endif /* SRC_COMMANDS_INTAKEINVERT_H_ */
