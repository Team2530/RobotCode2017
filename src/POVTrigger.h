/*
 * POVTrigger.h
 *
 *  Created on: May 30, 2017
 *      Author: Admin
 */

#ifndef POVTRIGGER_H_
#define POVTRIGGER_H_

#include <GenericHID.h>
#include <Buttons/Trigger.h>
#include <Buttons/Button.h>

class POVDirectionTrigger;

class POVTrigger : public frc::Button {
private:
	frc::GenericHID* joystick;
	int n;
public:
	POVTrigger(frc::GenericHID* source, int pov = 0);
	int GetValue();
	bool Get() override;
	POVDirectionTrigger* Direction(int direction);
	POVDirectionTrigger* N();
	POVDirectionTrigger* NE();
	POVDirectionTrigger* E();
	POVDirectionTrigger* SE();
	POVDirectionTrigger* S();
	POVDirectionTrigger* SW();
	POVDirectionTrigger* W();
	POVDirectionTrigger* NW();
	POVDirectionTrigger* Released();
};

class POVDirectionTrigger : public frc::Button {
private:
	POVTrigger* parent;
	int value;
public:
	POVDirectionTrigger(POVTrigger* pov, int direction);
	bool Get() override;
};

#endif /* POVTRIGGER_H_ */
