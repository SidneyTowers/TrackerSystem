/*----------------------------------------------------------------------------*\
| GenericMotor.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include "../../Headers/Motors/GenericMotor.h"

// Returns the position of the motor.
int GenericMotor::getPosition() {
	return Position;
}

// Sets the position of the motor to the requested position.
void GenericMotor::setPosition(int position) {
	this->Position = position;
}

