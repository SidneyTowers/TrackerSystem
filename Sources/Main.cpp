/*----------------------------------------------------------------------------*\
| Starter.cpp                                                                   |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include "../Headers/UserInterface/UserInterface.h"
#include "../Headers/TrackerSession.h"
#include "../Headers/SessionParameters.h"

// 
SessionParameters GlobalParameters;
TrackerSession * GlobalTracker = nullptr;

// 
int main(int argc, char **argv) {
	// 
	int ReturnValue = 0;

	// Create and utilize the user interface until it is no longer wanted, destroying it immediately
	delete ((new UserInterface(&GlobalParameters, &GlobalTracker))->Run(&ReturnValue, argc, argv));

	// Delete possible memory leak if data still exists
	if (GlobalTracker != nullptr) {
		delete GlobalTracker;
	}

	// 
	return ReturnValue;
}

