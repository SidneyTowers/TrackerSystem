/*----------------------------------------------------------------------------*\
| GenericMotor.h                                                               |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <cstdint>
#include <vector>
#include "../lib/wiringPi/AbstractOutputComponent.hpp"

#ifndef _GENERIC_MOTOR_H_
#define _GENERIC_MOTOR_H_


// Generic motor class with abstract method for reading and setting
//  the position of the motor.
class GenericMotor {
public:
	// Returns the position of the motor.
	AbstractOutputComponent *getController();

	// Sets the position of the motor to the requested position.
	void setError(int64_t error);
	
	int64_t getError();

	int64_t getLastError();

	int64_t isLastErrorSet();
	
	// This function actually updates the motor. It should be called every cycle.
	void update();
	
	// Moves the actuator in a direction at a power
	virtual void move(int32_t velocity) = 0;

protected:
	AbstractOutputComponent *actuatorController;
	int64_t error;
	double kp, ki, kd;
	int64_t integralActiveRange;
	int64_t integral;
	int64_t lastError;
	bool lastErrorSet;
	
	GenericMotor(AbstractOutputComponent *actuatorController, double kp,
				 double ki, double kd, int64_t integralActiveRange);
	
private:
	void pid();
};

#endif // _GENERIC_MOTOR_H_
