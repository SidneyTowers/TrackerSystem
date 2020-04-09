/*----------------------------------------------------------------------------*\
| SessionParameters.h                                                          |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _SESSION_PARAMETERS_H_
#define _SESSION_PARAMETERS_H_


#include <string>
#include "./Motors/MotorContainer.h"
#include "./HardwareInputs/InputDevice.h"
#include "./HardwareInputs/Display.h"

// Storage for parameters used in the current session
class SessionParameters {
public:
	// 
	Display * GetCameraOutput();

//private:
	// Pointer to the relavent input device
	InputDevice * CurrentDevice = nullptr;

	// Index of which input device to utilize
	unsigned char DeviceIndex = 0;

	// 
	MotorContainer * CurrentMotors = nullptr;

	// 
	void SetSessionParameters();
};

#endif // _SESSION_PARAMETERS_H_

