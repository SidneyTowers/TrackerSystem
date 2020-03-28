/*----------------------------------------------------------------------------*\
| MotorServo.cpp                                                               |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <wiringpi.h>
#include <iostream>
#include "../inc/MotorServo.h"

#define MOTOR_SERVO_MIN_POSITION (0)
#define MOTOR_SERVO_MAX_POSITION (100)

MotorServo::MotorServo(int pin) {
	this->pin = pin;
	
	softPwmCreate(pin, MOTOR_SERVO_MIN_POSITION, MOTOR_SERVO_MAX_POSITION);
}

void MotorServo::update() {
    if(Position > MOTOR_SERVO_MAX_POSITION)
        Position = MOTOR_SERVO_MAX_POSITION;
    if(Position < MOTOR_SERVO_MIN_POSITION)
        Position = MOTOR_SERVO_MIN_POSITION;
	
	softPWMWrite(pin, Position);
}
