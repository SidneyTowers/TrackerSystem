/*----------------------------------------------------------------------------*\
| SessionParameters.h                                                          |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _SESSION_PARAMETERS_H_
#define _SESSION_PARAMETERS_H_

#include <string>

// Storage for parameters used in the current session.
class SessionParameters {
public:
	// Control flag for enabling tracking the input device.
	bool trackingEnabled;
	// 
	void UpdateSessionParameters(std::string NewParameters);
};

#endif // _SESSION_PARAMETERS_H_