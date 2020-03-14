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

UserInterface::UserInterface(SessionParameters * GlobalParams, TrackerSession ** GlobalTracker) {
	PointerToParams = GlobalParams;
	PointerToTracker = GlobalTracker;
}

std::string UserInterface::ParseCommand(std::string CommandIn) {
	// method stub
	// std::string CommandIn;
	// std::cout << "Type 'session' to start simple proof." << std::endl << "Enter wanted command: ";
	// std::cin >> CommandIn;
	
	// std::cout << "Command Parsed (Placeholder for before graphical user interface implementation)" << std::endl;
	if (CommandIn.find("session") != std::string::npos) {
		*PointerToTracker = new TrackerSession(PointerToParams);
		(*PointerToTracker)->startTracking();
		return "Tracker Session Created";
	} else {
		PointerToParams->UpdateSessionParameters(CommandIn);
		return "Tracker Session Updated with commands" + CommandIn;
	}
}
