/*----------------------------------------------------------------------------*\
| MotorDisk.cpp                                                                |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _MOTOR_DISK_H_
#define _MOTOR_DISK_H_

#include "GenericMotor.h"

// Class for use with an spinning disk as the physical GenericMotor
//  to move the physical InputDevice.
class MotorDisk: public GenericMotor {
  public:
	void update();
};

#endif // _MOTOR_DISK_H_
