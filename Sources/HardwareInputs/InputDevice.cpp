/*----------------------------------------------------------------------------*\
| InputDevice.cpp                                                              |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include "../../Headers/HardwareInputs/InputDevice.h"

// 
InputDevice::InputDevice(DeviceType WantedDevice = DeviceType::NullType) {
	// 
	this->CurrentType = WantedDevice;
}

// 
DeviceType InputDevice::GetType() {
	// 
	return this->CurrentType;
}

