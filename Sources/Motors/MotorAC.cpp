/*----------------------------------------------------------------------------*\
| MotorAC.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <wiringPi.h>
#include <iostream>
#include "../inc/MotorAC.h"

#define AC_KP (.005)
#define AC_KI (.00001)
#define AC_KD (.00000001)
#define AC_INT_ACTIVE_RNG (20)


MotorAC::MotorAC(int pin)
		: GenericMotor(nullptr,
						AC_KP, AC_KI, AC_KD, (int64_t) AC_INT_ACTIVE_RNG) {
	
}

void MotorAC::move(int32_t velocity) {
	std::cout << "MotorAC::move()" << std::endl;
}
