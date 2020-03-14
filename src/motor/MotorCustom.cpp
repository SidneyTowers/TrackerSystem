/*----------------------------------------------------------------------------*\
| MotorCustom.cpp                                                              |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>

int MotorCustom::getPosition() {
	// method stub
	std::cout << "MotorCustom getPosition() = " << Position << std::endl;
}

void MotorCustom::setPosition(int New) {
	// method stub
	std::cout << "MotorCustom set (old = " << Position << ") ";
	Position = New;
	std::cout << "(new = " << New << ")" << std::endl;
}
