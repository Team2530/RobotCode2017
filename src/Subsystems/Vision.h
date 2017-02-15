#ifndef Vision_H
#define Vision_H

#include <Commands/Subsystem.h>
#include <NetworkTables/NetworkTable.h>
#include <Relay.h>

class Vision : public frc::Subsystem {
private:
	bool valid;
	double targets;
	double displacement;
	double distance;
	std::shared_ptr<NetworkTable> table;
	frc::Relay* LEDRing;
	const int kLEDRing = 0; // Spike relay is on port 0

public:
	Vision();
	void InitDefaultCommand();
	bool GetValid();
	double GetTargets();
	double GetDisplacement();
	double GetDistance();
	void SetLED(bool on);
	void Update();
	void Cancel();
};

#endif  // Vision_H
