/*----------------------------------------------------------------------------*\
| MotorCustom.cpp                                                              |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_CUSTOM_H_
#define _MOTOR_CUSTOM_H_

#include "./GenericMotor.h"


// Class for use with a stepper motor as the physical GenericMotor
//  to move the physical InputDevice.
class MotorCustom : public GenericMotor {
public:
	MotorCustom(int pin);

	void move(int32_t velocity);
};

#endif // _MOTOR_CUSTOM_H_
