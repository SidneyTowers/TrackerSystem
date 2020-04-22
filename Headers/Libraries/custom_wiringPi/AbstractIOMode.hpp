#ifndef _IO_MODE_HPP_
#define _IO_MODE_HPP_

#include <wiringPi.h>

/**
 * Class:		AbstractIOMode
 * Details:		Abstract mode that allows for inputs and outputs. Methods must be
 *				 initialized by a child class.
 */
class AbstractIOMode {
  private:
	/**
	 * Field:		pin
	 * Purpose:		The pin of associated with this IO mode.
	 */
	int pin;
  
  protected:
	/**
	 * Constructor:	AbstractIOMode
	 * Purpose:		Constructs an IO mode with the specified pin.
	 * Arguments:	pin-
	 *					The pin for the IO mode.
	 */
	AbstractIOMode(int pin) {
		this->pin = pin;
	}
	
  public:
	/**
	 * Method:		handleIO
	 * Purpose:		Abstract method that handles both input and output operations.
	 * Arguments:	value-
	 *					The value to be handled by a child class.
	 * Return:		A value calculated by a child class.
	 */
	virtual double handleIO(double value) = 0;
	
	/**
	 * Method:		getPin
	 * Purpose:		Returns the pin associated with this IO mode.
	 * Arguments:	N/A
	 * Return:		The pin associated with this IO mode.
	 */
	int getPin() {
		return pin;
	}
};

#endif // _IO_MODE_HPP_
