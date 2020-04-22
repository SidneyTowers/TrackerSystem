#ifndef _SERVO_HPP_
#define _SERVO_HPP_

#include <wiringPi.h>
#include "AbstractOutputComponent.hpp"
#include "AbstractOutputMode.hpp"

/**
 * Class:		Servo
 * Details:		Object representation of a physical 3-pin servo.
 */
class Servo: public AbstractOutputComponent {
  public:
	/**
	 * Constructor:	Servo
	 * Purpose:		Constructs a servo with the specified output mode.
	 * Arguments:	*mode-
	 *					The output mode for the servo.
	 */
	Servo(AbstractOutputMode *mode): AbstractOutputComponent(mode) {
		
	}
	
	/**
	 * Method:		setPosition
	 * Purpose:		Sets the position of this object.
	 * Arguments:	position-
	 *					the position to set this object to.
	 * Return:		void
	 */
	void setPosition(double position) {
		mode->setOutput(position);
	}
};

#endif // _SERVO_HPP_
