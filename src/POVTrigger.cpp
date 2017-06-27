/*
 * POVTrigger.cpp
 *
 *  Created on: May 30, 2017
 *      Author: Admin
 */

#include "POVTrigger.h"

POVTrigger::POVTrigger(frc::GenericHID* source, int pov) {
	joystick = source;
	n = pov;
}

int POVTrigger::GetValue() {
	return joystick->GetPOV(n);
}

bool POVTrigger::Get() {
	return GetValue() != -1;
}

POVDirectionTrigger* POVTrigger::Direction(int value) {
	return new POVDirectionTrigger(this, value);
}

POVDirectionTrigger* POVTrigger::N() {
	return Direction(0);
}

POVDirectionTrigger* POVTrigger::NE() {
	return Direction(45);
}

POVDirectionTrigger* POVTrigger::E() {
	return Direction(90);
}

POVDirectionTrigger* POVTrigger::SE() {
	return Direction(135);
}

POVDirectionTrigger* POVTrigger::S() {
	return Direction(180);
}

POVDirectionTrigger* POVTrigger::SW() {
	return Direction(225);
}

POVDirectionTrigger* POVTrigger::W() {
	return Direction(270);
}

POVDirectionTrigger* POVTrigger::NW() {
	return Direction(315);
}

POVDirectionTrigger* POVTrigger::Released() {
	return Direction(-1);
}

POVDirectionTrigger::POVDirectionTrigger(POVTrigger* pov, int direction) {
	parent = pov;
	value = direction;
}

bool POVDirectionTrigger::Get() {
	return parent->GetValue() == value;
}
