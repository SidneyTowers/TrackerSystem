/*----------------------------------------------------------------------------*\
| MotorDC.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <wiringPi.h>
#include <iostream>
#include "../inc/MotorDC.h"

#define DC_KP (.005)
#define DC_KI (.00001)
#define DC_KD (.00000001)
#define DC_INT_ACTIVE_RNG (20)


MotorDC::MotorDC(int pin)
		: GenericMotor(nullptr,
						DC_KP, DC_KI, DC_KD, (int64_t) DC_INT_ACTIVE_RNG) {

}

void MotorDC::move(int32_t velocity) {
	std::cout << "MotorDC::move()" << std::endl;
}
