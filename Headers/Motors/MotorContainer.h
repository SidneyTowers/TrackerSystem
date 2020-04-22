/*----------------------------------------------------------------------------*\
| GenericMotor.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_CONTAINER_H_
#define _MOTOR_CONTAINER_H_

#include <vector>
#include "GenericMotor.h"


// Generic motor class with abstract method for reading and setting
//  the position of the motor.
class MotorContainer: public std::vector<GenericMotor*> {
public:
	// Updates all motors in this container
	void updateAll();
};

#endif // _MOTOR_CONTAINER_H_
