/*----------------------------------------------------------------------------*\
| TrackerSession.h                                                             |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _TRACKER_SESSION_H_
#define _TRACKER_SESSION_H_
#pragma once

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
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

#endif // _TRACKER_SESSION_H_
