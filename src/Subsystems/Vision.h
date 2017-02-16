#ifndef Vision_H
#define Vision_H

#include <Commands/Subsystem.h>
#include <NetworkTables/NetworkTable.h>

class Vision : public Subsystem {
private:
	bool valid;
	double targets;
	double displacement;
	double distance;
	std::shared_ptr<NetworkTable> table;

public:
	Vision();
	bool GetValid();
	double GetTargets();
	double GetDisplacement();
	double GetDistance();
	void Update();
};

#endif  // Vision_H
