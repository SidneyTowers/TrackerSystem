/*----------------------------------------------------------------------------*\
| MotorServo.cpp                                                               |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_SERVO_H_
#define _MOTOR_SERVO_H_

#include "GenericMotor.h"

// Class for use with a servo as the physical GenericMotor
//  to move the physical InputDevice.
class MotorServo: public GenericMotor {
  public:
	// Creates a servo instance
	MotorServo(int pin);
	
	void update();
};

#endif // _MOTOR_SERVO_H_
