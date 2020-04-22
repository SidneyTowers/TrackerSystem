#ifndef _OUTPUT_MODE_HPP_
#define _OUTPUT_MODE_HPP_

#include <wiringPi.h>
#include "AbstractIOMode.hpp"

/**
 * Class:		AbstractOutputMode
 * Details:		Abstract mode that allows for outputs. Methods must be
 *				 initialized by a child class.
 */
class AbstractOutputMode: public AbstractIOMode {
  protected:
	/**
	 * Constructor:	AbstractOutputMode
	 * Purpose:		Constructs an output mode with the specified pin.
	 * Arguments:	pin-
	 *					The pin for the output mode.
	 */
	AbstractOutputMode(const int pin): AbstractIOMode(pin) {
		
	}
	
  public:
	/**
	 * Method:		handleIO
	 * Purpose:		Implementation of parent class AbstractIOMode. Calls
	 *				 setOutput(double) and returns 0.
	 * Arguments:	value-
	 *					The value to set the output as.
	 * Return:		Zero (0) always.
	 */
	double handleIO(double value) override {
		setOutput(value);
		return 0;
	}
	
	/**
	 * Method:		setOutput
	 * Purpose:		Abstract method that sets the output of the pin.
	 * Arguments:	amount-
	 *					The value to output.
	 * Return:		void
	 */
	virtual void setOutput(double amount) = 0;
};

#endif // _OUTPUT_MODE_HPP_
