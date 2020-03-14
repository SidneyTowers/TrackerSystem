/*----------------------------------------------------------------------------*\
| MotorAC.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include "../inc/MotorAC.h"

int MotorAC::getPosition() {
	// method stub
	std::cout << "MotorCustom getPosition() = " << Position << std::endl;
}

void MotorAC::setPosition(int New) {
	// method stub
	std::cout << "MotorAC Set" << std::endl;
	Position = New;
}
