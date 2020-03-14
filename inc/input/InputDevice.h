/*----------------------------------------------------------------------------*\
| InputDevice.h                                                                |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _INPUT_DEVICE_CPP_
#define _INPUT_DEVICE_CPP_

// Generic input class with abstract method for polling
//  the value of the input device.
class InputDevice {
  public:
	// Returns the value polled from the InputDevice.
	virtual int getValue() = 0;
};

#endif // _INPUT_DEVICE_CPP_