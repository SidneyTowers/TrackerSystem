/*----------------------------------------------------------------------------*\
| GenericMotor.h                                                               |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _GENERIC_MOTOR_H_
#define _GENERIC_MOTOR_H_
#pragma once

// Generic motor class with abstract method for reading and setting
//  the position of the motor.
class GenericMotor {
public:
	// Returns the position of the motor.
	int getPosition();

	// Sets the position of the motor to the requested position.
	void setPosition(int position);
	
	// This function actually updates the motor. It should be called every cycle.
	virtual void update() = 0;

protected:
	// 
	int Position;
	int pin;
};

#endif // _GENERIC_MOTOR_H_
