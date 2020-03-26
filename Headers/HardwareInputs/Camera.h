/*----------------------------------------------------------------------------*\
| Camera.h                                                                     |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _CAMERA_H_
#define _CAMERA_H_
#pragma once

#include "InputDevice.h"
#include "Display.h"

namespace Cam {
// Class for use with a physical camera as an InputDevice
class Camera: public InputDevice {
public:
	// Constructor for camera class
	Camera();

	// 
	unsigned char GetDeviceAmount();
	
	// Returns the value polled from the camera
	void * GetValue(int Location);
};
}
#endif // _CAMERA_H_
