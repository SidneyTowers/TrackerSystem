#ifndef _L293D_HPP_
#define _L293D_HPP_

#include <wiringPi.h>
#include <vector>
#include "AbstractIC.hpp"
#include "DigitalOutputMode.hpp"
#include "SoftPWMOutputMode.hpp"

/**
 * Class:		L293D
 * Details:		Object representation of a physical L293D chip.
 */
class L293D: public AbstractIC {
  private:
	/**
	 * Field:		*in1Pin
	 * Purpose:		Stores GPIO pin for first output to this object.
	 */
	DigitalOutputMode *in1Pin;
	/**
	 * Field:		*in2Pin
	 * Purpose:		Stores GPIO pin for the second output to this object.
	 */
	DigitalOutputMode *in2Pin;
	/**
	 * Field:		*enablePin
	 * Purpose:		Stores GPIO pin for the enable output to this object.
	 */
	SoftPWMOutputMode *enablePin;
	
  public:
	/**
	 * Constructor:	L293D
	 * Purpose:		Constructs a L293D chip with pins for the 2 inputs to the chip and an enable pin.
	 *				 Sets the input pins to digital output modes and the enable pin to a soft PWM mode.
	 * Arguments:	in1Pin-
	 *					The GPIO pin that the first input of the L293D is connected to.
	 *				in2Pin-
	 *					The GPIO pin that the second input of the L293D is connected to.
	 *				enablePin-
	 *					The GPIO pin that the enable input of the L293D is connected to.
	 */
	L293D(int in1Pin, int in2Pin, int enablePin) {
		this->in1Pin = new DigitalOutputMode(in1Pin);
		this->in2Pin = new DigitalOutputMode(in2Pin);
		this->enablePin = new SoftPWMOutputMode(enablePin, 0, 100);
	}
	/**
	 * Destructor:	L293D
	 * Purpose:		Frees the pointers to in1Pin, in2Pin, and enablePin.
	 * Arguments:	N/A
	 */
	~L293D() {
		if (in1Pin)
			free(in1Pin);
		if (in2Pin)
			free(in2Pin);
		if (enablePin)
			free(enablePin);
	}
	
	/**
	 * Method:		getPins
	 * Purpose:		Generates a vector containing the pins for this object.
	 * Arguments:	N/A
	 * Return:		A vector containing the pins for this object. The order of the pins is:
	 *				 the in1 pin, the in2 pin, then the enable pin.
	 */
	std::vector<int> getPins() override {
		std::vector<int> pins = {in1Pin->getPin(), in2Pin->getPin(), enablePin->getPin()};
		return pins;
	}
	
	/**
	 * Method:		setMotor
	 * Purpose:		Sets the speed of the motor attached to this object.
	 * Arguments:	speed-
	 *					The speed to set the motor to. Positive speeds will turn the motor
	 *					 in one direction while negative speeds turn the motor in the other
	 *					 direction. A larger magnitude will spin the motor faster.
	 * Return:		void
	 */
	void setMotor(int speed) {
		int speed1 = (speed > 0)? HIGH: LOW;
		int speed2 = (speed < 0)? HIGH: LOW;
		
		in1Pin->setOutput(speed1);
		in2Pin->setOutput(speed2);
		
		if (speed < 0)
			speed *= -1;
		
		enablePin->setOutput(speed);
	}
};

#endif // _L293D_HPP_
