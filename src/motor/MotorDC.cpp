/*----------------------------------------------------------------------------*\
| MotorDC.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include "../inc/MotorDC.h"

int MotorDC::getPosition() {
	// method stub
	std::cout << "MotorCustom getPosition() = " << Position << std::endl;
}

void MotorDC::setPosition(int New) {
	// method stub
	// method stub
	std::cout << "MotorCustom set (old = " << Position << ") ";
	Position = New;
	std::cout << "(new = " << New << ")" << std::endl;
}
