#include <climits>
#include "../inc/MotorContainer.h"
#include "../inc/GenericMotor.h"
#include "../inc/MotorCustom.h"
#include "../inc/MotorDC.h"
#include "../inc/MotorDisk.h"
#include "../inc/MotorServo.h"
#include "../inc/MotorStepper.h"
#include "../inc/MotorAC.h"

// Returns 1 if successful test, 0 if failed test
int setAndPrintMotor(GenericMotor* motor, int value) {
	motor->setPosition(value);
	std::cout << "set " << value << ": " << motor->getPosition() << std::endl;
	
	return motor->getPosition() == value;
}
void _test_MotorSetPosition(GenericMotor* motor) {
	std::cout << "old = " << motor->getPosition() << std::endl;
	
	assert(motor != NULL);
	
	if (!setAndPrintMotor(motor, 0) && 
		!setAndPrintMotor(motor, 100) && 
		!setAndPrintMotor(motor, -100) && 
		!setAndPrintMotor(motor, INT_MAX) && 
		!setAndPrintMotor(motor, -INT_MAX)) {
		
		std::cout << "TEST FAILURE" << std::endl;
		exit(-1);
	}
}

void _testAll_MotorSetPosition() {
	MotorCustom motorCustom;
	MotorDC motorDC;
	MotorDisk motorDisk;
	MotorServo motorServo;
	MotorStepper motorStepper;
	MotorAC motorAC;
	
	std::cout << "Test motorCustom" << std::endl;
	_test_MotorSetPosition(motorCustom);
	
	std::cout << "Test motorDC" << std::endl;
	_test_MotorSetPosition(motorDC);
	
	std::cout << "Test motorDisk" << std::endl;
	_test_MotorSetPosition(motorDisk);
	
	std::cout << "Test motorServo" << std::endl;
	_test_MotorSetPosition(motorServo);
	
	std::cout << "Test motorStepper" << std::endl;
	_test_MotorSetPosition(motorStepper);
	
	std::cout << "Test motorAC" << std::endl;
	_test_MotorSetPosition(motorAC);
}

int main() {
	_testAll_MotorSetPosition();
}
