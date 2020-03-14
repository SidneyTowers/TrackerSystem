/*----------------------------------------------------------------------------*\
| InputDeviceSignal.h                                                          |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _INPUT_DEVICE_SIGNAL_H_
#define _INPUT_DEVICE_SIGNAL_H_

// A logical representation of a signal from the InputDevice.
class InputDeviceSignal {
  public:
	// Returns the value polled from the InputDevice.
	virtual int getValue() = 0;
};

#endif // _INPUT_DEVICE_SIGNAL_H_
