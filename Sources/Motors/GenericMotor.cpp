/*----------------------------------------------------------------------------*\
| GenericMotor.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include "../../Headers/Motors/GenericMotor.h"

// Returns the position of the motor.
int GenericMotor::getPosition() {
	return Position;
}

// Sets the position of the motor to the requested position.
void GenericMotor::setPosition(int position) {
	this->Position = position;
}

