/*----------------------------------------------------------------------------*\
| MotorServo.cpp                                                               |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_SERVO_H_
#define _MOTOR_SERVO_H_

#include "GenericMotor.h"
#include "../lib/wiringPi/Servo.hpp"

#define MOTOR_SERVO_MIN_POSITION (4)
#define MOTOR_SERVO_MAX_POSITION (24)


// Class for use with a servo as the physical GenericMotor
//  to move the physical InputDevice.
class MotorServo: public GenericMotor {
  private:
	Servo *controllerRef;
	int lastPosition = 0;
	
  public:
	// Creates a servo instance
	MotorServo(int pin);
	
	void move(int32_t velocity);
};

#endif // _MOTOR_SERVO_H_
