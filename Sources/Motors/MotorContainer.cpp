/*----------------------------------------------------------------------------*\
| GenericMotor.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <vector>
#include "../inc/MotorContainer.h"
#include "../inc/GenericMotor.h"


void MotorContainer::updateAll() {
	for (GenericMotor *mot: *this) {
		mot->update();
	}
}
