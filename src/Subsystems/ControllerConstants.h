/*
 * ControllerConstants.h
 *
 *  Created on: Jan 28, 2017
 *      Author: celeste173
 */

#ifndef SRC_SUBSYSTEMS_CONTROLLERCONSTANTS_H_
#define SRC_SUBSYSTEMS_CONTROLLERCONSTANTS_H_

#include "WPILib.h"

class ControllerConstants{
public:
	//raw values for buttons
	enum xBoxButtonMap {
		kAbutton=1,
		kBbutton=2,
		kXbutton=3,
		kYbutton=4,
		kLBbutton=5,
		kRBbutton=6,
		kBackbutton=7,
		kStartbutton=8,
		kLSbutton=9,
		kRSbutton=10,

	};
	// raw values for axes
	enum xBoxAxisMap{
		kLSXAxis= 0,
		kLSYAxis= 1,
		kLTAxis= 2,
		kRTAxis= 3,
		kRSXAxis= 4,
		kRSYAxis= 5,
	};

	enum PWMPort{
		kPWM0=0,
		kPWM1=1,
		kPWM2=2,
		kPWM3=3,
		kPWM4=4,
		kPWM5=5,
		kPWM6=6,
		kPWM7=7,
		kPWM8=8,
		kPWM9=9,
	};

	enum DIOPort{
		kDIO0=0,
		kDIO1=1,
		kDIO2=2,
		kDIO3=3,
		kDIO4=4,
		kDIO5=5,
		kDIO6=6,
		kDIO7=7,
		kDIO8=8,
		kDIO9=9,
	};

	enum AnalogInputPort{
		kAIP0=0,
		kAIP1=1,
		kAIP2=2,
		kAIP3=3,
	};

	enum RelayPort{
		kRP0=0,
		kRP1=1,
		kRP2=2,
		kRP3=3,
	};

	enum USBJoystickPort{
		kUSB0=0,
		kUSB1=1,
		kUSB2=2,
		kUSB3=3,
		kUSB4=4,
		kUSB5=5,
	};

};

#endif /* SRC_SUBSYSTEMS_CONTROLLERCONSTANTS_H_ */
