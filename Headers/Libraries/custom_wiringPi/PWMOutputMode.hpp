#ifndef _PWM_OUTPUT_MODE_HPP_
#define _PWM_OUTPUT_MODE_HPP_

#include <wiringPi.h>
#include "AbstractOutputMode.hpp"

/**
 * Class:		PWMOutputMode
 * Details:		Outputs a 10-bit Pulse Wave Modulation (PWM) signal from a GPIO
 *				 pin. Only GPIO 1 can use the 10-bit PWM.
 */
class PWMOutputMode: public AbstractOutputMode {
  public:
	/**
	 * Field:		PWM_MAX
	 * Purpose:		Declares the maximum PWM value that can be sent to the pin.
	 */
	const static int PWM_MAX = 1024;
  
	/**
	 * Constructor:	PWMOutputMode
	 * Purpose:		Constructs an output mode with output to GPIO pin 1. Sets
	 *				 the pin mode to PWM_OUTPUT.
	 * Arguments:	N/A
	 */
	PWMOutputMode(): AbstractOutputMode(1) {
		pinMode(getPin(), PWM_OUTPUT);
	}
	
	/**
	 * Method:		setOutput
	 * Purpose:		Sets the output of GPIO pin 1 to the specified amount using
	 *				 a pwm write.
	 * Arguments:	amount-
	 *					The value of the output to GPIO pin 1 between 0 and 1.
	 * Return:		void
	 */
	void setOutput(double amount) override {
		pwmWrite(getPin(), amount * PWM_MAX);
	}
};

#endif // _PWM_OUTPUT_MODE_HPP_
