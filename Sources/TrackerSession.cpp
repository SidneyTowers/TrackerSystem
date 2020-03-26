/*----------------------------------------------------------------------------*\
| TrackerSession.cpp                                                           |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include "../Headers/SessionParameters.h"
#include "../Headers/TrackerSession.h"

// 
TrackerSession::TrackerSession(SessionParameters * GlobalParams) {
	PointerToParams = GlobalParams;
}

// 
TrackerSession::~TrackerSession() {
	std::cout << "Tracker Session Ending" << std::endl;
}

// 
void TrackerSession::setTrackMethod(int method) {
	// method stub
}

// 
void TrackerSession::startTracking() {
	std::cout << "Tracker Session Starting" << std::endl;
}
