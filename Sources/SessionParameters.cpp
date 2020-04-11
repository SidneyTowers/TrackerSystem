/*----------------------------------------------------------------------------*\
| SessionParameters.cpp                                                        |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include <string>
#include <iostream>
#include <FL/Fl_PNG_Image.H>
#include "../Headers/SessionParameters.h"

// 
void SessionParameters::SetSessionParameters() {
	// 
	return;
}

// 
Display * SessionParameters::GetCameraOutput() {
	// 
	Fl_RGB_Image * Buffer = (Fl_RGB_Image *)CurrentDevice->GetValue(DeviceIndex);
	Display * DisplayBuffer = new Display(Buffer->array, Buffer->w(), Buffer->h(), Buffer->d());
	delete Buffer;
	return DisplayBuffer;
}

