#ifndef _DIGITAL_OUTPUT_MODE_HPP_
#define _DIGITAL_OUTPUT_MODE_HPP_

#include <wiringPi.h>
#include "AbstractOutputMode.hpp"

/**
 * Class:		DigitalOutputMode
 * Details:		Outputs a digital signal from a GPIO pin.
 */
class DigitalOutputMode: public AbstractOutputMode {
  public:
	/**
	 * Constructor:	DigitalOutputMode
	 * Purpose:		Constructs an output mode with output to the specified pin.
	 *				 Sets the pin mode to OUTPUT.
	 * Arguments:	pin-
	 *					The GPIO pin that will be the output for the output
	 *					 mode.
	 */
	DigitalOutputMode(const int pin): AbstractOutputMode(pin) {
		pinMode(pin, OUTPUT);
	}
  
	/**
	 * Method:		setOutput
	 * Purpose:		Sets the output of the pin to the specified amount using a
	 *				 digital write.
	 * Arguments:	amount-
	 *					The amount that will be written to the pin.
	 * Return:		void
	 */
	void setOutput(double amount) override {
		digitalWrite(getPin(), amount);
	}
};

#endif // _DIGITAL_OUTPUT_MODE_HPP_
