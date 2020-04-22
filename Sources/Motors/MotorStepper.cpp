/*----------------------------------------------------------------------------*\
| MotorStepper.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <wiringPi.h>
#include <iostream>
#include <cmath>
#include <memory>
#include "../inc/MotorStepper.h"
#include "../lib/wiringPi/ULN2003.hpp"

#define STEPPER_KP (.005)
#define STEPPER_KI (.00001)
#define STEPPER_KD (.00000001)
#define STEPPER_INT_ACTIVE_RNG (20)


MotorStepper::MotorStepper(const std::vector<int>& pins)
		: GenericMotor((controllerRef = new StepperOutputComponent(ULN2003_HALF_STEP, pins)),
					   STEPPER_KP, STEPPER_KI, STEPPER_KD, (int64_t) STEPPER_INT_ACTIVE_RNG) {
	
}

void MotorStepper::move(int32_t velocity) {
	if (velocity > 0)
		controllerRef->getController()->stepForward();
	else if (velocity < 0)
		controllerRef->getController()->stepBackward();
}
