/*----------------------------------------------------------------------------*\
| MotorServo.cpp                                                               |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include <cstdint>
#include "../inc/MotorServo.h"
#include "../lib/wiringPi/SoftPWMOutputMode.hpp"
#include "../lib/wiringPi/Servo.hpp"

#define SERVO_KP (.005)
#define SERVO_KI (.00001)
#define SERVO_KD (.00000001)
#define SERVO_INT_ACTIVE_RNG (20)
#define SERVO_INITAL_PWM (0)
#define SERVO_PWM_RANGE  (200)


MotorServo::MotorServo(int pin)
		: GenericMotor((controllerRef = new Servo(new SoftPWMOutputMode(pin, SERVO_INITAL_PWM, SERVO_PWM_RANGE))),
						SERVO_KP, SERVO_KI, SERVO_KD, (int64_t) SERVO_INT_ACTIVE_RNG) {
}

void MotorServo::move(int32_t position) {
	lastPosition += position;
	
	if (lastPosition > MOTOR_SERVO_MAX_POSITION)
		lastPosition = MOTOR_SERVO_MAX_POSITION;
    else if (lastPosition < MOTOR_SERVO_MIN_POSITION)
        lastPosition = MOTOR_SERVO_MIN_POSITION;
	
	controllerRef->setPosition(lastPosition);
}
