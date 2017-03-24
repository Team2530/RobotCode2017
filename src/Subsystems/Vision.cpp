#include "Vision.h"
#include "../RobotMap.h"
#include "../Commands/PullVisionEstimate.h"

Vision::Vision() : Subsystem("VisionSubsystem") {
	valid = false;
	targets = 0;
	displacement = 0;
	distance = 0;

	table = NetworkTable::GetTable("GearAutonomous");

	// Get the USB camera from CameraServer,
	// start streaming to dashboard
	// (the vision processing will pick it up thusly)
	camera = frc::CameraServer::GetInstance()->StartAutomaticCapture("USB Camera 0", 0);
	// Set the resolution
	camera.SetResolution(320, 240);
	camera.SetBrightness(100);
	SetExposure(true);
}

void Vision::InitDefaultCommand() {
	SetDefaultCommand(new PullVisionEstimate());
}

void Vision::SetExposure(bool manual) {
	manual = true;
	if (manual) {
		camera.SetExposureManual(20); // TODO: do negative values work?? apparently
	} else {
		camera.SetExposureAuto();
	}
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
	valid = targets > 0;
	// Detect NaN values: these are NOT valid!
	if (displacement != displacement || distance != distance) {
		valid = false;
	} else if (valid) {
		//std::printf("Dist %f, disp %f", distance, displacement);
	}
}

void Vision::Cancel() {
	valid = false;
	targets = 0;
	displacement = 0;
	distance = 0;
}
