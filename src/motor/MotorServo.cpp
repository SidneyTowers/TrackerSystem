/*----------------------------------------------------------------------------*\
| MotorServo.cpp                                                               |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include "../inc/MotorServo.h"

int MotorServo::getPosition() {
	// method stub
	std::cout << "MotorCustom getPosition() = " << Position << std::endl;
}

void MotorServo::setPosition(int New) {
	// method stub
	// method stub
	std::cout << "MotorCustom set (old = " << Position << ") ";
	Position = New;
}
