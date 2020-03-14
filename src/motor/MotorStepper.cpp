/*----------------------------------------------------------------------------*\
| MotorStepper.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>

int MotorStepper::getPosition() {
	// method stub
	std::cout << "MotorCustom getPosition() = " << Position << std::endl;
}

void MotorStepper::setPosition(int New) {
	// method stub
	std::cout << "MotorStepper Set" << std::endl;
	Position = New;
}
