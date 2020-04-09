/*----------------------------------------------------------------------------*\
| Starter.cpp                                                                   |
|                                                                              |
|                                                                              |
| Febuary 18, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include "UserInterface.cpp"
#include "TrackerSession.h"
#include "SessionParameters.h"

// 
SessionParameters GlobalParameters;
TrackerSession * GlobalTracker = nullptr;

// 
int main() {
	if(wiringPiSetup() == -1){
        printf("setup wiringPi failed!");
        return 1; 
    }
	
	UserInterface NewUser(&GlobalParameters, &GlobalTracker);
	while (NewUser.ParseCommand());
	if (GlobalTracker != nullptr) {
		delete GlobalTracker;
	}
}

