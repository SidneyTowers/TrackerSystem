#ifndef _OUTPUT_COMPONENT_HPP_
#define _OUTPUT_COMPONENT_HPP_

#include <wiringPi.h>
#include <cstdlib>
#include "Component.hpp"
#include "AbstractOutputMode.hpp"

/**
 * Class:		AbstractOutputComponent
 * Details:		A Component that has one output mode with one output pin.
 */
class AbstractOutputComponent: public Component {
  protected:
	/**
	 * Field:		*mode
	 * Purpose:		The output mode of this component.
	 */
	AbstractOutputMode *mode;
	
	/**
	 * Constructor:	AbstractOutputComponent
	 * Purpose:		Constructs a component with the specified output mode.
	 * Arguments:	*mode-
	 *					The output mode for the component
	 */
	AbstractOutputComponent(AbstractOutputMode *mode): Component() {
		this->mode = mode;
	}
	/**
	 * Destructor:	AbstractOutputComponent
	 * Purpose:		Frees the pointer to the mode.
	 * Arguments:	N/A
	 */
	virtual ~AbstractOutputComponent() {
		if (mode)
			free(mode);
	}
	
  public:
	/**
	 * Method:		getPin
	 * Purpose:		Returns the pin associated with the output mode.
	 * Arguments:	N/A
	 * Return:		The pin associated with the output mode.
	 */
	int getPin() {
		return mode->getPin();
	}
};

#endif // _OUTPUT_COMPONENT_HPP_
