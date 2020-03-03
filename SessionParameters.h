/*----------------------------------------------------------------------------*\
| SessionParameters.h                                                          |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#pragma once

#include <string>

// Storage for parameters used in the current session.
class SessionParameters {
public:
	// Control flag for enabling tracking the input device.
	bool trackingEnabled;
	// 
	void UpdateSessionParameters(std::string NewParameters);
};
