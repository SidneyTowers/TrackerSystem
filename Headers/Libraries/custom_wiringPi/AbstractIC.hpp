#ifndef _ABSTRACT_IC_HPP_
#define _ABSTRACT_IC_HPP_

#include <wiringPi.h>
#include <vector>
#include "Component.hpp"

/**
 * Class:		AbstractIC
 * Details:		A Component that has one or more IO pins.
 */
class AbstractIC: public Component {
  protected:
	/**
	 * Constructor:	AbstractIC
	 * Purpose:		Dummy constructor that only allows 
	 *				 child classes to instantiate.
	 * Arguments:	N/A
	 */
	AbstractIC() {
		
	}
	
  public:
	/**
	 * Method:		getPins
	 * Purpose:		Abstract method that returns a vector of the pins on this IC.
	 * Arguments:	N/A
	 * Return:		A vector of the pins on this IC.
	 */
	virtual std::vector<int> getPins() = 0;
};

#endif // _ABSTRACT_IC_HPP_
