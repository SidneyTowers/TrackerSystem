/*----------------------------------------------------------------------------*\
| Pixel.cpp                                                                    |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include "../../Headers/HardwareInputs/Pixel.h"

// 
Pixel::Pixel(unsigned char * DataPointer, unsigned long int DataCountStart, unsigned char ChannelCount) {
	if (DataPointer == nullptr) return;
	for (int i = 0; i < ChannelCount; ++i) {
		Channels[i] = DataPointer[DataCountStart + i];
	}
	ChannelAmount = ChannelCount;
}

// 
unsigned char Pixel::GetRedChannel() {
	if (ChannelAmount <= 0) {
		return 0;
	} else {
		return Channels[0];
	}
}

// 
unsigned char Pixel::GetBlueChannel() {
	if (ChannelAmount <= 2) {
		return 0;
	} else {
		return Channels[1];
	}
}

// 
unsigned char Pixel::GetGreenChannel() {
	if (ChannelAmount <= 2) {
		return 0;
	} else {
		return Channels[2];
	}
}

// 
unsigned char Pixel::GetAlphaChannel() {
	if (ChannelAmount <= 2) {
		return Channels[1];
	} else {
		return Channels[3];
	}
}

