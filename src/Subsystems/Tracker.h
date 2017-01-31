#ifndef Tracker_H
#define Tracker_H

#include <Commands/Subsystem.h>

class Tracker : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Tracker();
	void InitDefaultCommand();
};

#endif  // Tracker_H
