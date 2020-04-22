/*----------------------------------------------------------------------------*\
| MotorDC.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_DC_H_
#define _MOTOR_DC_H_

#include "GenericMotor.h"
#include "../lib/wiringPi/L293D.hpp"


// Class for use with an DC motor as the physical GenericMotor
//  to move the physical InputDevice.
class MotorDC: public GenericMotor {
  public:
	MotorDC(int pin);
	
	void move(int32_t velocity);
};

#endif // _MOTOR_DC_H_
