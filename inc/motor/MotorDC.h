/*----------------------------------------------------------------------------*\
| MotorDC.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_DC_H_
#define _MOTOR_DC_H_

#include "GenericMotor.h"

// Class for use with an DC motor as the physical GenericMotor
//  to move the physical InputDevice.
class MotorDC: public GenericMotor {
  public:
	// Returns the position of the motor.
	int getPosition();
	
	// Sets the position of the motor to the requested position.
	void setPosition(int New);
};

#endif // _MOTOR_DC_H_
