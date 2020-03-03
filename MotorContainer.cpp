/*----------------------------------------------------------------------------*\
| GenericMotor.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <vector>
#include "GenericMotor.h"
#include "MotorAC.cpp"
#include "MotorDC.cpp"
#include "MotorDisk.cpp"
#include "MotorServo.cpp"
#include "MotorStepper.cpp"
#include "MotorCustom.cpp"

// Generic motor class with abstract method for reading and setting
//  the position of the motor.
class MotorContainer {
public:
	// 
	MotorContainer(unsigned char MotorAmount, std::vector<unsigned char> MotorTypes) {
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
				MotorArray.at(Counter) = new MotorServo();
			}
			else if (MotorTypes.at(Counter) == 4) {
				MotorArray.at(Counter) = new MotorStepper();
			}
			else {
				MotorArray.at(Counter) = new MotorCustom();
			}
		}
	}

private:
	// 
	std::vector<GenericMotor*> MotorArray;
};
