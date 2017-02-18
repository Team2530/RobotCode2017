#ifndef LED_H
#define LED_H

#include <Commands/Subsystem.h>
#include <Relay.h>

class LED : public Subsystem {
private:
	frc::Relay* LEDRing;
	const int kLEDRing = 0; // Spike relay is on port 0

	bool state = false;

public:
	LED();
	void InitDefaultCommand();
	void Toggle();
	void Set(bool on);
};

#endif  // LED_H
/*
 * LED.h
 *
 *  Created on: Feb 18, 2017
 *      Author: Shadotiz
 */
#ifndef LED_H
#define LED_H

#include <Commands/Subsystem.h>
#include <Relay.h>

class LED : public Subsystem {
private:
  frc::Relay* LEDRing;
  const int kLEDRing = 0; // Spike relay is on port 0

  bool state = false;

public:
  LED();
  void InitDefaultCommand();
  void Toggle();
  void Set(bool on);
};

#endif  // LED_H
