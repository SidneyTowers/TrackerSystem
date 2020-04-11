/*----------------------------------------------------------------------------*\
| InputDevice.h                                                                |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _INPUT_DEVICE_CPP_
#define _INPUT_DEVICE_CPP_
#pragma once

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include <cstdint>

// 
enum DeviceType : uint8_t {
	NullType = 0,
	Camera = 1,
	Microphone = 2
};

// Generic input class with abstract method for polling the value of the input device
class InputDevice {
public:
	// 
	InputDevice(DeviceType WantedDevice);

	// Returns the value polled from the InputDevice
	virtual void * GetValue(int Location) = 0;

	// 
	virtual unsigned char GetDeviceAmount() = 0;

	// Returns the type of the device (simplistic version of seperation without
	//     overwritting polymorphism or creation a reflection system)
	DeviceType GetType();

private:
	// 
	DeviceType CurrentType;
};

#endif // _INPUT_DEVICE_CPP_

