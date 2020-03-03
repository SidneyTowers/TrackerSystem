/*----------------------------------------------------------------------------*\
| UserInterface.cpp                                                            |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include "SessionParameters.h"
#include "TrackerSession.h"

// The user interface for the current session. Currently
//  parses command inputs.
class UserInterface {

public:
	// 
	UserInterface(SessionParameters * GlobalParams, TrackerSession ** GlobalTracker) {
		PointerToParams = GlobalParams;
		PointerToTracker = GlobalTracker;
	}

	// Parses input from the UserInterface to run commands.
	bool ParseCommand() {
		// method stub
		std::string CommandIn;
		std::cout << "Type 'session' to start simple proof." << std::endl << "Enter wanted command: ";
		std::cin >> CommandIn;

		// 
		std::cout << "Command Parsed (Placeholder for before graphical user interface implementation)" << std::endl;
		if (CommandIn.find("session") != std::string::npos) {
			*PointerToTracker = new TrackerSession(PointerToParams);
			(*PointerToTracker)->startTracking();
			return false;
		} else {
			PointerToParams->UpdateSessionParameters(CommandIn);
			return true;
		}
	}

private:
	// 
	SessionParameters * PointerToParams;
	TrackerSession ** PointerToTracker;
};
