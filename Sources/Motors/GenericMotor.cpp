/*----------------------------------------------------------------------------*\
| GenericMotor.cpp                                                             |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <cstdint>
#include <vector>
#include "../inc/GenericMotor.h"


AbstractOutputComponent* GenericMotor::getController() {
	return this->actuatorController;
}

void GenericMotor::setError(int64_t error) {
	this->error = error;
	
	if (!lastErrorSet) {
		lastError = error;
		lastErrorSet = true;
	}
}

int64_t GenericMotor::getError() {
	return this->error;
}

int64_t GenericMotor::getLastError() {
	return this->lastError;
}

int64_t GenericMotor::isLastErrorSet() {
	return this->lastErrorSet;
}


void GenericMotor::update() {
	pid();
}


GenericMotor::GenericMotor(AbstractOutputComponent *actuatorController, double kp, double ki, double kd, int64_t integralActiveRange) {
	this->kp = kp;
	this->ki = ki;
	this->kd = kd;
	this->integralActiveRange = integralActiveRange;
	this->integral = 0;
	this->lastError = 0;
	this->lastErrorSet = false;
}

void GenericMotor::pid() {
	if (error == 0 || std::abs(error) > integralActiveRange)
		integral = 0;
	else
		integral += error;
		
	int64_t derivative = error - lastError;
	lastError = error;
	
	int velocity = kp * error
				 + ki * integral
				 + kd * derivative;
			  
	move(velocity);
}
