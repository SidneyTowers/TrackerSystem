/*----------------------------------------------------------------------------*\
| Microphone.h                                                                 |
|                                                                              |
|                                                                              |
| March 14, 2020        Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MICROPHONE_H_
#define _MICROPHONE_H_
#pragma once

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include <iostream>
#include "./InputDevice.h"

namespace Mic {
// Class for use with a physical microphone as an InputDevice.
class Microphone: public InputDevice {
  public:
	// Constructor for Microphone class.
	Microphone();

	// 
	unsigned char GetDeviceAmount();
	
	// Returns the value polled from the Microphone.
	void * GetValue(int Location);
};
}
#endif // _MICROPHONE_H_
