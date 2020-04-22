/*----------------------------------------------------------------------------*\
| MotorCustom.cpp                                                              |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include <wiringPi.h>
#include "../inc/MotorCustom.h"

#define CUSTOM_KP (.005)
#define CUSTOM_KI (.00001)
#define CUSTOM_KD (.00000001)
#define CUSTOM_INT_ACTIVE_RNG (20)


MotorCustom::MotorCustom(int pin)
		: GenericMotor(nullptr,
						CUSTOM_KP, CUSTOM_KI, CUSTOM_KD, (int64_t) CUSTOM_INT_ACTIVE_RNG) {
				
}

void MotorCustom::move(int32_t velocity) {
	std::cout << "MotorCustom::move()" << std::endl;
}
