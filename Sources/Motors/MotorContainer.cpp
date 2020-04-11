/*----------------------------------------------------------------------------*\
| GenericMotor.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include <vector>
#include "../../Headers/Motors/MotorContainer.h"
#include "../../Headers/Motors/GenericMotor.h"
#include "../../Headers/Motors/MotorAC.h"
#include "../../Headers/Motors/MotorDC.h"
#include "../../Headers/Motors/MotorDisk.h"
//#include "../../Headers/Motors/MotorServo.h"
#include "../../Headers/Motors/MotorStepper.h"
#include "../../Headers/Motors/MotorCustom.h"

// Generic motor class with abstract method for reading and setting
//  the position of the motor.
MotorContainer::MotorContainer(unsigned char MotorAmount, std::vector<unsigned char> MotorTypes) {
	MotorArray.resize(MotorAmount - 1);
	for (unsigned char Counter = 0; (Counter < MotorAmount) && !(Counter >= 254); ++Counter) {
		if (MotorTypes.at(Counter) == 0) {
			MotorArray.at(Counter) = new MotorAC();
		}
		else if (MotorTypes.at(Counter) == 1) {
			MotorArray.at(Counter) = new MotorDC();
		}
		else if (MotorTypes.at(Counter) == 2) {
			MotorArray.at(Counter) = new MotorDisk();
		}
		else if (MotorTypes.at(Counter) == 3) {
			//MotorArray.at(Counter) = new MotorServo(0);
		}
		else if (MotorTypes.at(Counter) == 4) {
			MotorArray.at(Counter) = new MotorStepper();
		}
		else {
			MotorArray.at(Counter) = new MotorCustom();
		}
	}
}

