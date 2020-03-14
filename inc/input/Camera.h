/*----------------------------------------------------------------------------*\
| Camera.h                                                                     |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "./InputDevice.cpp"

// Class for use with a physical camera as an InputDevice.
class Camera: public InputDevice {
  public:
	// Constructor for Camera class.
	Camera();
	
	// Returns the value polled from the Camera.
	int getValue();
};

#endif // _CAMERA_H_