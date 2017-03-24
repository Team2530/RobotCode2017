#ifndef Vision_H
#define Vision_H

#include <Commands/Subsystem.h>
#include <NetworkTables/NetworkTable.h>

#include <CameraServer.h>

class Vision : public frc::Subsystem {
private:
	bool valid;
	double targets;
	double displacement;
	double distance;
	std::shared_ptr<NetworkTable> table;
	cs::UsbCamera camera;

public:
	Vision();
	void InitDefaultCommand();
	void SetExposure(bool manual);
	bool GetValid();
	double GetTargets();
	double GetDisplacement();
	double GetDistance();
	void Update();
	void Cancel();
};

#endif  // Vision_H
