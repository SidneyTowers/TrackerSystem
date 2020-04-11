/*----------------------------------------------------------------------------*\
| MotorAC.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_AC_H_
#define _MOTOR_AC_H_
#pragma once

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include "GenericMotor.h"

// Class for use with an AC motor as the physical GenericMotor
//  to move the physical InputDevice.
class MotorAC: public GenericMotor {
  public:
	void update();
};

#endif // _MOTOR_AC_H_
