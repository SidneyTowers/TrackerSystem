/*----------------------------------------------------------------------------*\
| Display.cpp                                                                  |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "../../Headers/HardwareInputs/Display.h"

// Create the display in a user friendly format (not using other people's libraries)
Display::Display(const unsigned char * NewData, uint16_t Width, uint16_t Height, uint8_t Depth) {
	Rows = Height;
	Columns = Width;
	Channels = Depth;
	Data = (unsigned char *)malloc(Rows * Columns * Channels);
	std::memcpy(Data, NewData, (Rows * Columns * Channels));
}

// Create the display as a duplicate of the passed in display
Display::Display(const Display& DisplayToCopy) {
	Rows = DisplayToCopy.Rows;
	Columns = DisplayToCopy.Columns;
	Channels = DisplayToCopy.Channels;
	Data = (unsigned char *)malloc(Rows * Columns * Channels);
	std::memcpy(Data, DisplayToCopy.Data, (Rows * Columns * Channels));
}

// Delete the data array, if it exists, as to prevent memory leaks
Display::~Display() {
	if (Data != nullptr) {
		delete [] Data;
	}
}

// Returns the wanted pixel at the given location (1..Columns x 1..Rows)
Pixel Display::At(uint16_t X, uint16_t Y) {
	if ((X <= Columns) && (Y <= Rows) && (Y > 0) && (X > 0)) {
		Pixel Buffer(Data, ((Columns * (Y - 1) * Channels) + ((X - 1) * Channels)), Channels);
		return Buffer;
	} else {
		Pixel Buffer(nullptr, 0, 0);
		return Buffer;
	}
}

