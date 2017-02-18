#ifndef Vision_H
#define Vision_H

#include <Commands/Subsystem.h>
#include <NetworkTables/NetworkTable.h>

class Vision : public frc::Subsystem {
private:
	bool valid;
	double targets;
	double displacement;
	double distance;
	std::shared_ptr<NetworkTable> table;

public:
	Vision();
	void InitDefaultCommand();
	bool GetValid();
	double GetTargets();
	double GetDisplacement();
	double GetDistance();
	void Update();
	void Cancel();
};

#endif  // Vision_H
