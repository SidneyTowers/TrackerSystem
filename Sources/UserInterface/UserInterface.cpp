/*----------------------------------------------------------------------------*\
| UserInterface.cpp                                                            |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#include <iostream>
#include <string>
// #include <FL/Fl_Box.H>
// #include <FL/Fl_Tabs.H>
// #include <FL/Fl_Choice.H>
// #include <FL/Fl_Simple_Counter.H>
// #include <FL/Fl_PNG_Image.H>
// #include "opencv2/opencv.hpp"
#include "../../Headers/UserInterface/UserInterface.h"
#include "../../Headers/SessionParameters.h"
#include "../../Headers/TrackerSession.h"
#include "../../Headers/HardwareInputs/InputDevice.h"
#include "../../Headers/HardwareInputs/Camera.h"
#include "../../Headers/HardwareInputs/Microphone.h"
/*
// 
UserInterface::UserInterface(SessionParameters * GlobalParams, TrackerSession ** GlobalTracker) {
	std::cout << "\nUser Interface class is created now\n";
	PointerToParams = GlobalParams;
	PointerToTracker = GlobalTracker;
}

// 
UserInterface::~UserInterface() {
	std::cout << "\nUser Interface class is destroyed now\n\n";
}

// 
void UserInterface::CreateIntroWindow() {
	// 
	GlobalWindow = new Fl_Window(360, 125, "Tracker System");
	CurrentWindow = new Fl_Group(0, 0, 360, 125);
	GlobalWindow->color(FL_DARK2);
	CurrentWindow->color(FL_DARK2);
	GlobalWindow->add(CurrentWindow);
	GlobalWindow->resizable(CurrentWindow);
	Fl_Box * InfoText = new Fl_Box(20, 10, 320, 25, "Select Tracker System Input Device Type");
	CurrentWindow->add(InfoText);
	Fl_Button * CamButton = new Fl_Button(20, 40, 150, 35, "Camera");
	CurrentWindow->add(CamButton);
	CamButton->callback(CallInputWindowCreation, (void *)this);
	Fl_Button * MicButton = new Fl_Button(190, 40, 150, 35, "Microphone");
	CurrentWindow->add(MicButton);
	//MicButton->callback((Fl_Callback*)CallInputWindowCreation, this);
	Fl_Button * AdvancedButton = new Fl_Button(20, 80, 320, 35, "Click Here to skip to advanced mode");
	CurrentWindow->add(AdvancedButton);
	AdvancedButton->callback((Fl_Callback*)CallAdvancedWindowCreation, this);
	AdvancedButton->down_box(FL_NO_BOX);
}

// 
void UserInterface::CreateInputDeviceWindow(Fl_Widget * w) {
	GlobalWindow->resizable(nullptr);
	GlobalWindow->size(400, 600);
	CurrentWindow->resizable(nullptr);
	CurrentWindow->size(400, 600);
	GlobalWindow->resizable(CurrentWindow);
	bool IsMicrophone = false;
	for (int i = 0; i < CurrentWindow->children(); ++i) {
		if (CurrentWindow->child(i)->changed()) {
			if (CurrentWindow->child(i)->label() == "Camera") {
				//std::cout << CurrentWindow->child(i)->label();
				IsMicrophone = false;
			} else if (CurrentWindow->child(i)->label() == "Microphone") {
				//std::cout << CurrentWindow->child(i)->label();
				IsMicrophone = true;
			}
		}
	}
	CurrentWindow->clear();
	Fl_Button * SwapButton = new Fl_Button(20, 10, (IsMicrophone ? 140 : 160), 25, (IsMicrophone ? "Swap To Camera" : "Swap To Microphone"));
	CurrentWindow->add(SwapButton);
	Fl_Box * InfoText = new Fl_Box((IsMicrophone ? 125 : 145), 10, (IsMicrophone ? 125 : 145), 25, (IsMicrophone ? "Microphone" : "Camera"));
	CurrentWindow->add(InfoText);
	if (IsMicrophone) {
		PointerToParams->CurrentDevice = new Mic::Microphone();
	} else {
		PointerToParams->CurrentDevice = new Cam::Camera();
	}

	// 
	void * InputData = ((PointerToParams->CurrentDevice != nullptr) ? PointerToParams->CurrentDevice->GetValue(0) : nullptr);

	// 
	if (InputData != nullptr) {
		if (IsMicrophone) {
			exit(0);
		} else {
			Fl_Box * CameraImage = new Fl_Box(20, 40, 320, 200);
			CameraImage->color(FL_BLUE);
			CurrentWindow->add(CameraImage);
			CameraImage->image(((Fl_RGB_Image*)InputData)->copy(320, 200));
			CameraImage->redraw();
		}
	}

	// 
	Fl_Choice * CameraOptions = new Fl_Choice(20, 245, 180, 25);
	if (PointerToParams->CurrentDevice->GetDeviceAmount() >= 1) {
		for (int i = 0; i < PointerToParams->CurrentDevice->GetDeviceAmount(); ++i) {
			CameraOptions->add(("Device #"), 0, nullptr);
		}
	} else {
		CameraOptions->add("No devices available");
		CameraOptions->value(0);
	}
	CurrentWindow->add(CameraOptions);
	Fl_Button * MotorsButton = new Fl_Button(205, 245, 135, 25, "To Motors");
	CurrentWindow->add(MotorsButton);
	MotorsButton->callback(CallMotorWindowCreation, (void *)this);
}

// 
void UserInterface::CallInputWindowCreation(Fl_Widget * w, void * object) {
	((UserInterface*)object)->CreateInputDeviceWindow(w);
}

// 
void UserInterface::CreateMotorWindow(Fl_Widget * w) {
	GlobalWindow->resizable(nullptr);
	GlobalWindow->size(800, 600);
	CurrentWindow->resizable(nullptr);
	CurrentWindow->size(800, 600);
	GlobalWindow->resizable(CurrentWindow);
	for (int i = 0; i < CurrentWindow->children(); ++i) {
		if (CurrentWindow->child(i)->label() == "To Motors") {
			Fl_Widget * Buffer = CurrentWindow->child(i);
			CurrentWindow->remove(CurrentWindow->child(i));
			delete Buffer;
		}
	}

	// 
	Fl_Button * MotorButton = new Fl_Button(360, 40, 100, 25, "Motor One");
	CurrentWindow->add(MotorButton);

	// 
	Fl_Button * AddMotorButton = new Fl_Button(360, 70, 100, 25, "Add Motor");
	CurrentWindow->add(AddMotorButton);

	// 
	Fl_Box * InfoText = new Fl_Box(475, 10, 80, 25, "Motor Pins:");
	CurrentWindow->add(InfoText);

	// 
	Fl_Tabs * MotorPins = new Fl_Tabs(475, 40, 280, 200);
	{
		// 
		Fl_Group * PinDefaults = new Fl_Group(470, 60, 280, 175, "One");
		{
			// 
			Fl_Simple_Counter * PinOne = new Fl_Simple_Counter(480, 67.5, 60, 25, "Pin One");
			PinOne->step(1, 1);
			PinOne->minimum(0);

			// 
			Fl_Simple_Counter * PinTwo = new Fl_Simple_Counter(515, 67.5, 60, 25);
			PinTwo->step(1, 1);
			PinTwo->minimum(0);

			// 
			Fl_Simple_Counter * PinThree = new Fl_Simple_Counter(550, 67.5, 60, 25);
			PinThree->step(1, 1);
			PinThree->minimum(0);

			// 
			Fl_Simple_Counter * PinFour = new Fl_Simple_Counter(585, 67.5, 60, 25);
			PinFour->step(1, 1);
			PinFour->minimum(0);

			// 
			Fl_Simple_Counter * PinFive = new Fl_Simple_Counter(480, 147.5, 60, 25);
			PinFive->step(1, 1);
			PinFive->minimum(0);

			// 
			Fl_Simple_Counter * PinSix = new Fl_Simple_Counter(515, 147.5, 60, 25);
			PinSix->step(1, 1);
			PinSix->minimum(0);

			// 
			Fl_Simple_Counter * PinSeven = new Fl_Simple_Counter(550, 147.5, 60, 25);
			PinSeven->step(1, 1);
			PinSeven->minimum(0);

			// 
			Fl_Simple_Counter * PinEight = new Fl_Simple_Counter(585, 147.5, 60, 25);
			PinEight->step(1, 1);
			PinEight->minimum(0);
		}
		PinDefaults->end();

		// 
		Fl_Group * AddNewPin = new Fl_Group(470, 60, 280, 175, "Add");
		{
			// 
			
		}
		AddNewPin->end();
	}
	MotorPins->end();
	CurrentWindow->add(MotorPins);

	// 
	Fl_Button * TrackerStartButton = new Fl_Button(600, 565, 180, 25, "Start Tracking Session");
	CurrentWindow->add(TrackerStartButton);
}

// 
void UserInterface::CallMotorWindowCreation(Fl_Widget * w, void * object) {
	((UserInterface*)object)->CreateMotorWindow(w);
}

// 
void UserInterface::CreateAdvancedWindow(Fl_Widget * w) {
	CreateInputDeviceWindow(w);
	CreateMotorWindow(w);
}

// 
void UserInterface::CallAdvancedWindowCreation(Fl_Widget * w, void * object) {
	((UserInterface*)object)->CreateAdvancedWindow(w);
}

// 
UserInterface * UserInterface::Run(int * ReturnValue, int argc, char ** argv) {
	CreateIntroWindow();
	GlobalWindow->end();
	GlobalWindow->show(argc, argv);
	//this->AddAnim({0, 0.4, CurrentWindow, 0, 0, 800, 400, 400, 200, 0, 0});
	//Fl::add_timeout(0.04, this->Player, this);
	(*ReturnValue) = Fl::run();
	return this;
}

// 
void UserInterface::EndAnims() {
	switch (AnimEndState) {
		case Transitions::Null :
		default:
			return;
	}
}

// 
void UserInterface::Player(void * object) {
	((UserInterface*)object)->AnimPlayback();
}

// 
void UserInterface::AnimPlayback(void) {
	if (Animations.empty()) {
		this->EndAnims();
		return;
	} else {
		for (std::vector<AnimData>::iterator CurrentAnim = Animations.begin(); (Animations.size() != 0 && CurrentAnim != Animations.end()); ++CurrentAnim) {
			float BufferTime = ((*CurrentAnim).AnimDeltaTime / (*CurrentAnim).WantedAnimTime);
			if ((((*CurrentAnim).WantedX - (*CurrentAnim).StarterX) == 0) && (((*CurrentAnim).WantedY - (*CurrentAnim).StarterY) == 0)) {
				(*CurrentAnim).AnimTarget->size(((((*CurrentAnim).WantedWidth - (*CurrentAnim).StarterWidth) * BufferTime) + (*CurrentAnim).StarterWidth), ((((*CurrentAnim).WantedHeight - (*CurrentAnim).StarterHeight) * BufferTime) + (*CurrentAnim).StarterHeight));
			} else if ((((*CurrentAnim).WantedWidth - (*CurrentAnim).StarterWidth) == 0) && (((*CurrentAnim).WantedHeight - (*CurrentAnim).StarterHeight) == 0)) {
				(*CurrentAnim).AnimTarget->position(((((*CurrentAnim).WantedX - (*CurrentAnim).StarterX) * BufferTime) + (*CurrentAnim).StarterX), ((((*CurrentAnim).WantedY - (*CurrentAnim).StarterY) * BufferTime) + (*CurrentAnim).StarterY));
			} else {
				(*CurrentAnim).AnimTarget->resize(((((*CurrentAnim).WantedX - (*CurrentAnim).StarterX) * BufferTime) + (*CurrentAnim).StarterX), ((((*CurrentAnim).WantedY - (*CurrentAnim).StarterY) * BufferTime) + (*CurrentAnim).StarterY), ((((*CurrentAnim).WantedWidth - (*CurrentAnim).StarterWidth) * BufferTime) + (*CurrentAnim).StarterWidth), ((((*CurrentAnim).WantedHeight - (*CurrentAnim).StarterHeight) * BufferTime) + (*CurrentAnim).StarterHeight));
			}
			if ((*CurrentAnim).AnimTarget->parent() != nullptr || (*CurrentAnim).AnimTarget->parent() != NULL) (*CurrentAnim).AnimTarget->parent()->redraw();
			(*CurrentAnim).AnimTarget->redraw();
			(*CurrentAnim).AnimDeltaTime += 0.04;
			if (((*CurrentAnim).AnimDeltaTime - (*CurrentAnim).WantedAnimTime) >= -0.001) {
				(*CurrentAnim).AnimTarget->resize((*CurrentAnim).WantedX, (*CurrentAnim).WantedY, (*CurrentAnim).WantedWidth, (*CurrentAnim).WantedHeight);
				CurrentAnim = this->Animations.erase(CurrentAnim);
			}
		}
		Fl::repeat_timeout(0.04, this->Player, this);
	}
}

// 
void UserInterface::AddAnim(AnimData NewAnim) {
	Animations.push_back(NewAnim);
}

// 
void UserInterface::one() {
	// Creation and starting of the wanted tracker session
	*PointerToTracker = new TrackerSession(PointerToParams);
	(*PointerToTracker)->startTracking();
}

// 
void UserInterface::two(std::string CommandIn) {
	// Update session parameters
	//PointerToParams->UpdateSessionParameters(CommandIn);
}
*/
