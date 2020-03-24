/*----------------------------------------------------------------------------*\
| GenericMotor.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include "../inc/GenericMotor.h"

// Returns the position of the motor.
int getPosition() {
	return Position;
}

// Sets the position of the motor to the requested position.
void setPosition(int position) {
	this->Position = position;
}
