/*----------------------------------------------------------------------------*\
| MotorDisk.cpp                                                                |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include "../inc/MotorDisk.h"

int MotorDisk::getPosition() {
	// method stub
	std::cout << "MotorCustom getPosition() = " << Position << std::endl;
}

void setPosition(int New) {
	// method stub
	// method stub
	std::cout << "MotorCustom set (old = " << Position << ") ";
	Position = New;
	std::cout << "(new = " << New << ")" << std::endl;
}
