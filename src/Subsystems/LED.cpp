#include "LED.h"
#include "../RobotMap.h"

#include "Robot.h"

LED::LED() : Subsystem("LEDSubsystem") {
	LEDRing = new frc::Relay(kLEDRing, frc::Relay::Direction::kForwardOnly);
	state = false;
}

void LED::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void LED::Toggle() {
	Set(!state);
}

void LED::Set(bool on) {
	LEDRing->Set(on ? frc::Relay::Value::kForward : frc::Relay::Value::kOff);
	state = on;
	Robot::vision->SetExposure(on);
}

