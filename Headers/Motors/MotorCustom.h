/*----------------------------------------------------------------------------*\
| MotorCustom.cpp                                                              |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_CUSTOM_H_
#define _MOTOR_CUSTOM_H_
#pragma once

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include "./GenericMotor.h"

// Class for use with a stepper motor as the physical GenericMotor
//  to move the physical InputDevice.
class MotorCustom : public GenericMotor {
public:
	void update();
};

#endif // _MOTOR_CUSTOM_H_
