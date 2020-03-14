/*----------------------------------------------------------------------------*\
| UserInterface.cpp                                                            |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _USER_INTERFACE_H_
#define _USER_INTERFACE_H_

#include <string>
#include "SessionParameters.h"
#include "TrackerSession.h"

// The user interface for the current session. Currently
//  parses command inputs.
class UserInterface {
public:
	// 
	UserInterface(SessionParameters * GlobalParams, TrackerSession ** GlobalTracker);

	// Parses input from the UserInterface to run commands.
	// Returns a std::string containing information that can be shown to the user.
	std::string ParseCommand(std::string CommandIn);

private:
	// 
	SessionParameters * PointerToParams;
	TrackerSession ** PointerToTracker;
};

#endif // _USER_INTERFACE_H_
