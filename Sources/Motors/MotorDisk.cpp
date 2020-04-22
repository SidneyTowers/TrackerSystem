/*----------------------------------------------------------------------------*\
| MotorDisk.cpp                                                                |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <wiringPi.h>
#include <iostream>
#include "../inc/MotorDisk.h"

#define DISK_KP (.005)
#define DISK_KI (.00001)
#define DISK_KD (.00000001)
#define DISK_INT_ACTIVE_RNG (20)


MotorDisk::MotorDisk(int pin)
		: GenericMotor(nullptr,
						DISK_KP, DISK_KI, DISK_KD, (int64_t) DISK_INT_ACTIVE_RNG) {

}

void MotorDisk::move(int32_t velocity) {
	std::cout << "MotorDisk::move()" << std::endl;
}
