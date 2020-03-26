/*----------------------------------------------------------------------------*\
| InputDevice.cpp                                                              |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

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

