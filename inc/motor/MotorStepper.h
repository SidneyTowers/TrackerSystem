/*----------------------------------------------------------------------------*\
| MotorStepper.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_STEPPER_H_
#define _MOTOR_STEPPER_H_

#include "GenericMotor.h"

// Class for use with a stepper motor as the physical GenericMotor
//  to move the physical InputDevice.
class MotorStepper: public GenericMotor {
  public:
	// Returns the position of the motor.
	int getPosition();
	
	// Sets the position of the motor to the requested position.
	void setPosition(int New);
};

#endif // _MOTOR_STEPPER_H_
