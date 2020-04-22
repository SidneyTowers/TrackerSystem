#ifndef _ULN2003_HPP_
#define _ULN2003_HPP_

#include <wiringPi.h>
#include <vector>
#include <iostream>
#include "AbstractIC.hpp"


class ULN2003: public AbstractIC {
  private:
	std::vector<AbstractOutputMode*> modes;
	std::vector<int> steps;
	
	class UndefinedStepPattern: public std::exception {
		const char *what() const throw() {
			return "ULN2003 step pattern not defined. Use ULN2003::setStepPattern(std::vector<int>).";
		}
	};
  
	void step(int delta) {
		static int index = 0;
		
		if (steps.size() == 0)
			throw UndefinedStepPattern();
		
		setPins(steps[index]);
		
		index = (index + delta) % steps.size();
	}
	
	void setPins(int bits) {
		std::cout << "stepping: ";
		for (int i = 0; i < (signed) modes.size(); i++) {
			modes[i]->setOutput(((bits >> i) & 0x01));
			std::cout << ((bits >> i) & 0x01) << " ";
		}
		std::cout << std::endl;
	}
	
  public:
	// static const std::vector<int> HALF_STEP;
	// static const std::vector<int> FULL_STEP;
	// static const std::vector<int> TORQUE_FULL_STEP;
	
	  
	ULN2003(std::vector<AbstractOutputMode*> modes) {
		this->modes = modes;
	}
	ULN2003() {
		
	}
	~ULN2003() {
		for (AbstractOutputMode *mode: modes)
			if (mode)
				free(mode);
	}
	
	std::vector<int> getPins() override {
		std::vector<int> pins;
		
		for (AbstractOutputMode *mode: modes)
			pins.push_back(mode->getPin());
		
		return pins;
	}
	
	void addOutputPin(AbstractOutputMode *mode) {
		modes.push_back(mode);
	}
	
	void stepForward() {
		step(1);
	}
	
	void stepBackward() {
		step(-1);
	}
	
	void setStepPattern(std::vector<int> bitSteps) {
		this->steps = bitSteps;
	}
	
	std::vector<int> getStepPattern() {
		return this->steps;
	}
};


// const std::vector<int> ULN2003::HALF_STEP = {
	// 0b1000,
	// 0b1100,
	// 0b0100,
	// 0b0110,
	// 0b0010,
	// 0b0011,
	// 0b0001,
	// 0b1001
// };
// const std::vector<int> ULN2003::FULL_STEP = {
	// 0b1000,
	// 0b0100,
	// 0b0010,
	// 0b0001
// };
// const std::vector<int> ULN2003::TORQUE_FULL_STEP = {
	// 0b1100,
	// 0b0110,
	// 0b0011,
	// 0b1001
// };

const std::vector<int> ULN2003_HALF_STEP = {
	0b1000,
	0b1100,
	0b0100,
	0b0110,
	0b0010,
	0b0011,
	0b0001,
	0b1001
};
const std::vector<int> ULN2003_FULL_STEP = {
	0b1000,
	0b0100,
	0b0010,
	0b0001
};
const std::vector<int> ULN2003_TORQUE_FULL_STEP = {
	0b1100,
	0b0110,
	0b0011,
	0b1001
};


#endif // _ULN2003_HPP_
