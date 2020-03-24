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
	void update();
};

#endif // _MOTOR_STEPPER_H_
