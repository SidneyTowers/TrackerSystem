/*----------------------------------------------------------------------------*\
| TrackerSession.h                                                             |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#pragma once

#include <iostream>
#include "SessionParameters.h"

// Controller for tracking the InputDevice using the associated GenericMotors.
class TrackerSession {
public:
	// 
	TrackerSession(SessionParameters * GlobalParams);

	// 
	~TrackerSession();

	// Control flag for the type of input device as well as the type of motor input.
	int controlType;

	// Sets the method for which the tracker will track.
	void setTrackMethod(int method);

	// Initiates the input device tracking.
	void startTracking();

private:
	// 
	SessionParameters * PointerToParams;
};
