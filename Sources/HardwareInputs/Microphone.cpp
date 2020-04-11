/*----------------------------------------------------------------------------*\
| Microphone.cpp                                                               |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include <iostream>
#include "../../Headers/HardwareInputs/Microphone.h"

using namespace Mic;

Microphone::Microphone() : InputDevice(DeviceType::Microphone) {
	// method stub
	std::cout << "Microphone created" << std::endl;
}

// 
unsigned char Microphone::GetDeviceAmount() {
	// method stub
	return 0;
}

// 
void * Microphone::GetValue(int Location) {
	// method stub
	return nullptr;
}

