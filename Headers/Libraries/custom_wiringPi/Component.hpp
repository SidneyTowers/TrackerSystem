#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <wiringPi.h>

/**
 * Class:		Component
 * Details:		The ancestor class to all physical components represented in this library.
 */
class Component {
  protected:
	/**
	 * Constructor:	Component
	 * Purpose:		Dummy constructor that only allows calls by child classes.
	 * Arguments:	N/A
	 */
	Component() {
		
	}
};

#endif // _COMPONENT_HPP_
