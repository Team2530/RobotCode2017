/*
 * Intake.h
 *
 *  Created on: Jan 26, 2017
 *      Author: Jason Mitchell
 */

#ifndef SRC_SUBSYSTEMS_INTAKE_H_
#define SRC_SUBSYSTEMS_INTAKE_H_

#include "WPILib.h"
#include <Commands/Subsystem.h>

class Intake : public Subsystem {
private:
	static constexpr int kIntakeChannel = 5;
	VictorSP* intakeMotor;
public:
	Intake();
	void InitDefaultCommand();
	void IntakeOn();
	void IntakeOff();
	void IntakeInvert();
};




#endif /* SRC_SUBSYSTEMS_INTAKE_H_ */
