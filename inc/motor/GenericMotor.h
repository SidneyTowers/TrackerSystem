/*----------------------------------------------------------------------------*\
| GenericMotor.h                                                               |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _GENERIC_MOTOR_H_
#define _GENERIC_MOTOR_H_

// Generic motor class with abstract method for reading and setting
//  the position of the motor.
class GenericMotor {
public:
	// Returns the position of the motor.
	virtual int getPosition() = 0;

	// Sets the position of the motor to the requested position.
	virtual void setPosition(int position) = 0;

protected:
	// 
	int Position;
};

#endif // _GENERIC_MOTOR_H_
