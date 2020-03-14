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
	// Returns the position of the motor.
	int getPosition();

	// Sets the position of the motor to the requested position.
	void setPosition(int New);
};

#endif // _MOTOR_CUSTOM_H_
