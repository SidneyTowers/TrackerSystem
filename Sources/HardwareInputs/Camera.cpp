/*----------------------------------------------------------------------------*\
| Camera.cpp                                                                   |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include <FL/Fl_Image.H>
#include <FL/Fl_PNG_Image.H>
#include "../../Headers/HardwareInputs/Camera.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

// Laziness for both the Camera class' namespace (which was needed to avoid a
//     namespace ambiguity issue) and the OpenCV general namespace
using namespace cv;
using namespace Cam;

// Constructor for Camera class
Camera::Camera() : InputDevice(DeviceType::Camera) {
	// Empty method, as all functionality is done within the parent class
}

// Returns the amount of camera devices found that can be used
unsigned char Camera::GetDeviceAmount() {
	// Create wanted local variables
	VideoCapture Capture;
	unsigned char Count = 0;

	// Loop through a max of 256 cameras for input
	for (unsigned int i; i <=255; ++i) {

		// If the open fails (there is no device), then break the for loop
		if(!Capture.open(i)) {
        	break;

		// Otherwise, increment the device count
		} else {
			++Count;
		}
	}

	// Return the generated count value
	return Count;
}

// Returns the value polled from the Camera
void * Camera::GetValue(int Location) {
	// 
    VideoCapture Capture;
	Mat * Frame = new Mat();

    // If no camera is available, set frame to nullptr
    if(!Capture.open(Location)) {
        Frame = nullptr;
	} else {

		// If the camera returns no image, set frame to nullptr
		Capture >> (*Frame);
	    if(Frame->empty()) {
			Frame = nullptr;
		}
	}

	// If frame is nullptr, then return a default error image
	if (Frame == nullptr) {
		std::cout << "Program failed to get any data from the wanted camera\n";
		return new Fl_PNG_Image("no-image-available-icon.png");
    }

    // Else, return the generated camera image converted into a supported FLTK format
    std::cout << "Program ran successfully\n";
	Fl_RGB_Image * Buffer = new Fl_RGB_Image(Frame->data, Frame->cols, Frame->rows, Frame->dims);
	delete Frame;
    return Buffer;
}

