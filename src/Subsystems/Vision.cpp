#include "Vision.h"
#include "../RobotMap.h"
#include "../Commands/PullVisionEstimate.h"

#include <CameraServer.h>

Vision::Vision() : Subsystem("VisionSubsystem") {
	valid = false;
	targets = 0;
	displacement = 0;
	distance = 0;
	table = NetworkTable::GetTable("GearAutonomous");

	// Get the USB camera from CameraServer,
	// start streaming to dashboard
	// (the vision processing will pick it up thusly)
	cs::UsbCamera camera = frc::CameraServer::GetInstance()->StartAutomaticCapture("USB Camera 0", 0);
	// Set the resolution
	camera.SetResolution(320, 240);
	camera.SetExposureManual(20);
	camera.SetBrightness(100);
}

void Vision::InitDefaultCommand() {
	SetDefaultCommand(new PullVisionEstimate());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
bool Vision::GetValid() {
	return valid;
}
double Vision::GetTargets() {
	return targets;
}
double Vision::GetDisplacement() {
	return displacement;
}
double Vision::GetDistance() {
	return distance;
}

void Vision::Update() {
	targets = table->GetNumber("targets", 0);
	displacement = table->GetNumber("displacementIn", 0);
	distance = table->GetNumber("distanceIn", 0);
	valid = targets == 2;
	// Detect NaN values: these are NOT valid!
	if (displacement != displacement || distance != distance) {
		valid = false;
	} else if (valid) {
		std::printf("Dist %f, disp %f", distance, displacement);
	}
}

void Vision::Cancel() {
	valid = false;
	targets = 0;
	displacement = 0;
	distance = 0;
}
