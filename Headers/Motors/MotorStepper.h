/*----------------------------------------------------------------------------*\
| MotorStepper.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_STEPPER_H_
#define _MOTOR_STEPPER_H_

#include "GenericMotor.h"
#include "../lib/wiringPi/AbstractOutputComponent.hpp"
#include "../lib/wiringPi/ULN2003.hpp"
#include "../lib/wiringPi/DigitalOutputMode.hpp"


class StepperOutputComponent: public AbstractOutputComponent {
  protected:
	ULN2003 *controller;
	
  public:
	StepperOutputComponent(const std::vector<int> pattern, const std::vector<int> pins)
			: AbstractOutputComponent(nullptr) {
		controller = new ULN2003();
		controller->setStepPattern(pattern);
		
		for (int pin: pins)
			controller->addOutputPin(new DigitalOutputMode(pin));
	}
	virtual ~StepperOutputComponent() = default;

	ULN2003* getController() {
		return this->controller;
	}
};


// Class for use with a stepper motor as the physical GenericMotor
//  to move the physical InputDevice.
class MotorStepper: public GenericMotor {
  private:
	StepperOutputComponent *controllerRef;
	
  public:
	MotorStepper(const std::vector<int>&);
  
	void move(int32_t velocity);
};

#endif // _MOTOR_STEPPER_H_
