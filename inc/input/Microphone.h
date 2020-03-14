/*----------------------------------------------------------------------------*\
| Microphone.h                                                                 |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MICROPHONE_H_
#define _MICROPHONE_H_

#include <iostream>
#include "./InputDevice.h"

// Class for use with a physical microphone as an InputDevice.
class Microphone: public InputDevice {
  public:
	// Constructor for Microphone class.
	Microphone();
	
	// Returns the value polled from the Microphone.
	int getValue();
};

#endif // _MICROPHONE_H_
