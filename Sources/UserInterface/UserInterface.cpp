/*----------------------------------------------------------------------------*\
| UserInterface.cpp                                                            |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include <iostream> // For debugging purposes only
#include <string>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Simple_Counter.H>
#include <FL/Fl_PNG_Image.H>
#include "opencv2/opencv.hpp"
#include "../../Headers/UserInterface/UserInterface.h"
#include "../../Headers/SessionParameters.h"
#include "../../Headers/TrackerSession.h"
#include "../../Headers/HardwareInputs/InputDevice.h"
#include "../../Headers/HardwareInputs/Camera.h"
#include "../../Headers/HardwareInputs/Microphone.h"


// Constructor for the UserInterface class
UserInterface::UserInterface(SessionParameters * GlobalParams, TrackerSession ** GlobalTracker) {
	// 
	PointerToParams = GlobalParams;
	PointerToTracker = GlobalTracker;

	// Create a fixed array of "static" strings for the motor list
	for (int i = 0; i < 20; ++i) {
		buffer.push_back("        ");
	}

	// Create a fixed array of "static" strings for the device lists
	for (int i = 0; i < 20; ++i) {
		deviceBuffer.push_back("        ");
	}
}


// Destructor for the UserInterface class
UserInterface::~UserInterface() {
	std::cout << "\nUser Interface class is destroyed now\n\n";
	// Handle any potential memory leaks here, which i don't believe there are any as of now
}


// Function for the creation of the introduction window (the first window ever seen)
void UserInterface::CreateIntroWindow() {
	// 
	GlobalWindow = new Fl_Window(360, 125, "Tracker System");
	CurrentWindow = new Fl_Group(0, 0, 360, 125);

	// 
	GlobalWindow->color(FL_DARK2);
	CurrentWindow->color(FL_DARK2);

	// 
	GlobalWindow->add(CurrentWindow);
	GlobalWindow->resizable(CurrentWindow);

	// 
	Fl_Box * InfoText = new Fl_Box(20, 10, 320, 25, "Select Tracker System Input Device Type");
	CurrentWindow->add(InfoText);

	// 
	Fl_Button * CamButton = new Fl_Button(20, 40, 150, 35, "Camera");
	CamButton->callback(CallInputWindowCreation, (void *)this);
	CurrentWindow->add(CamButton);

	// 
	Fl_Button * MicButton = new Fl_Button(190, 40, 150, 35, "Microphone");
	//MicButton->callback((Fl_Callback*)CallInputWindowCreation, this);
	CurrentWindow->add(MicButton);

	// 
	Fl_Button * AdvancedButton = new Fl_Button(20, 80, 320, 35, "Click Here to skip to advanced mode");
	AdvancedButton->callback((Fl_Callback*)CallAdvancedWindowCreation, (void *)this);
	AdvancedButton->down_box(FL_NO_BOX);
	CurrentWindow->add(AdvancedButton);
}


// Function for the creation of the input device specific handling side of the application's window
void UserInterface::CreateInputDeviceWindow(Fl_Widget * w) {
	// 
	GlobalWindow->resizable(nullptr);
	GlobalWindow->size(400, 650);
	CurrentWindow->resizable(nullptr);
	CurrentWindow->size(400, 650);
	GlobalWindow->resizable(CurrentWindow);

	// 
	bool IsMicrophone = false;

	// 
	for (int i = 0; i < CurrentWindow->children(); ++i) {

		// 
		if (CurrentWindow->child(i)->changed()) {

			// 
			if (CurrentWindow->child(i)->label() == "Camera") {
				IsMicrophone = false;

			// 
			} else if (CurrentWindow->child(i)->label() == "Microphone") {
				IsMicrophone = true;
			}
		}
	}

	// 
	CurrentWindow->clear();

	// 
	Fl_Button * SwapButton = new Fl_Button(20, 10, (IsMicrophone ? 140 : 160), 25, (IsMicrophone ? "Swap To Camera" : "Swap To Microphone"));
	CurrentWindow->add(SwapButton);

	// 
	Fl_Box * InfoText = new Fl_Box(250, 10, 140, 25, (IsMicrophone ? "Microphone" : "Camera"));
	InfoText->align(FL_ALIGN_LEFT);
	CurrentWindow->add(InfoText);

	// 
	if (!IsMicrophone) {
		// 
		Fl_Box * SharpenText = new Fl_Box(155, 347, 140, 25, "Sharpened Image:");
		SharpenText->align(FL_ALIGN_LEFT);
		CurrentWindow->add(SharpenText);

		// 
		Fl_Choice * SharpenOptions = new Fl_Choice(160, 345, 220, 25);

		// Add all currently supported Motor Types as individual options
		SharpenOptions->add("No sharpening");
		SharpenOptions->add("Light sharpening");
		SharpenOptions->add("Medium sharpening");
		SharpenOptions->add("Heavy sharpening");

		// Set the option to default to the no motor type selected option
		SharpenOptions->value(0);

		// 
		//SharpenOptions->callback(nullptr);

		// 
		CurrentWindow->add(SharpenOptions);
	}

	// 
	if (IsMicrophone) {
		exit(0);
		//PointerToParams->CurrentDevice = new Mic::Microphone();

	// 
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
			Fl_Box * CameraImage = new Fl_Box(20, 40, 360, 260);
			CurrentWindow->add(CameraImage);
			CameraImage->image(((Fl_RGB_Image*)InputData)->copy(360, 260));
			CameraImage->redraw();
			Fl_Box * NewCameraImage = new Fl_Box(20, 375, 360, 260);
			CurrentWindow->add(NewCameraImage);
			NewCameraImage->image(((Fl_RGB_Image*)InputData)->copy(360, 260));
			NewCameraImage->redraw();
		}
	}

	// 
	Fl_Choice * CameraOptions = new Fl_Choice(20, 305, 220, 25);

	// 
	if (PointerToParams->CurrentDevice->GetDeviceAmount() >= 1) {

		// 
		for (int i = 0; i < PointerToParams->CurrentDevice->GetDeviceAmount(); ++i) {
			deviceBuffer.at(i) = "Device " + std::to_string(i);
			CameraOptions->add(deviceBuffer.at(i).c_str(), 0, nullptr);
		}

	// 
	} else {
		CameraOptions->add("No devices available");
		CameraOptions->value(0);
	}

	// 
	CurrentWindow->add(CameraOptions);
	Fl_Button * MotorsButton = new Fl_Button(245, 305, 135, 25, "To Motors");
	CurrentWindow->add(MotorsButton);

	// 
	MotorsButton->callback(CallMotorWindowCreation, (void *)this);
}


// Function for allowing the call to the CreateInputDeviceWindow function, due to FLTK function pointer
//     calls requiring the function to be static, but requiring non-static functionality from the
//     wanted function
void UserInterface::CallInputWindowCreation(Fl_Widget * w, void * object) {
	((UserInterface*)object)->CreateInputDeviceWindow(w);
}


// Function for the creation of the motor specific handling side of the application's window
void UserInterface::CreateMotorWindow(Fl_Widget * w) {
	// 
	GlobalWindow->resizable(nullptr);
	GlobalWindow->size(800, 650);
	CurrentWindow->resizable(nullptr);
	CurrentWindow->size(800, 650);
	GlobalWindow->resizable(CurrentWindow);

	// Loop through all currently created widgets
	for (int i = 0; i < CurrentWindow->children(); ++i) {

		// Find the "To Motors" button and delete it safely, without memory leaks
		if (CurrentWindow->child(i)->label() == "To Motors") {
			Fl_Widget * Buffer = CurrentWindow->child(i);
			CurrentWindow->remove(CurrentWindow->child(i));
			delete Buffer;
		}
	}

	// 
	MotorInfo.push_back(new Fl_Button(395, 40, 90, 25, "Motor 1"));
	MotorInfo[0]->callback(UpdateMotorCaller, (void *)this);
	CurrentWindow->add(MotorInfo[0]);

	// 
	MotorInfo.push_back(new Fl_Button(395, 70, 90, 25, "Add Motor"));
	MotorInfo[1]->callback(AddMotorCaller, (void *)this);
	CurrentWindow->add(MotorInfo[1]);

	// 
	Fl_Box * InfoText = new Fl_Box(475, 10, 80, 25, "Motor Information:");
	CurrentWindow->add(InfoText);

	// 
	MotorTabs = new Fl_Tabs(490, 40, 285, 460);
	{
		// 
		Fl_Group * MotorDefault = new Fl_Group(490, 40, 285, 460);
		{
			// 
			Fl_Choice * MotorOptions = new Fl_Choice(500, 50, 260, 25);

			// Add all currently supported Motor Types as individual options
			MotorOptions->add("No motor type selected");
			MotorOptions->add("Servo Motor");
			MotorOptions->add("Stepper Motor");
			MotorOptions->add("DC Motor");
			MotorOptions->add("Custom Motor");

			// Set the option to default to the no motor type selected option
			MotorOptions->value(0);

			// 
			MotorOptions->callback(MotorInterfaceChangeCaller, (void *)this);

		}
		MotorDefault->end();
	}
	MotorTabs->end();
	CurrentWindow->add(MotorTabs);

	// 
	Fl_Button * TrackerStartButton = new Fl_Button(600, 610, 180, 25, "Start Tracking Session");
	CurrentWindow->add(TrackerStartButton);
}


// Function for allowing the call to the MotorInterfaceChange function, due to FLTK function pointer
//     calls requiring the function to be static, but requiring non-static functionality from the
//     wanted function
void UserInterface::MotorInterfaceChangeCaller(Fl_Widget * CallingWidget, void * object) {
	((UserInterface*)object)->MotorInterfaceChange(CallingWidget);
}


// Function for handling the Motor Interface changes for each motor type
void UserInterface::MotorInterfaceChange(Fl_Widget * CallingWidget) {
	switch (((Fl_Choice*)CallingWidget)->value()) {
		// Servo motor information
		case 1:
			std::cout << "Servo Motor" << std::endl;
			break;

		// Stepper motor information
		case 2:
			std::cout << "Stepper Motor" << std::endl;
			break;

		// DC motor information
		case 3:
			std::cout << "DC Motor" << std::endl;
			break;

		// Custom motor information
		case 4:
			std::cout << "Custom Motor" << std::endl;
			break;

		// Default back to the no motor type selected motor information
		case 0:
		default:
			std::cout << "No motor type selected" << std::endl;
			break;
	}
}


// Function for allowing the call to the AddMotor function, due to FLTK function pointer calls
//     requiring the function to be static, but requiring non-static functionality from the
//     wanted function
void UserInterface::AddMotorCaller(Fl_Widget * CallingWidget, void * object) {
	((UserInterface*)object)->AddMotor(CallingWidget);
}


// Function for handling the addition of a new motor to the large motor array
void UserInterface::AddMotor(Fl_Widget * CallingWidget) {
	// 
	buffer.at(MotorInfo.size() - 1) = ("Motor " + std::to_string(MotorInfo.size()));
	MotorInfo[MotorInfo.size() - 1]->label(buffer.at(MotorInfo.size() - 1).c_str());
	MotorInfo[MotorInfo.size() - 1]->callback(UpdateMotorCaller, (void *)this);
	MotorInfo[MotorInfo.size() - 1]->redraw();

	// Create a new Pin information group within the Fl_Tabs section
	Fl_Group * MotorDefault = new Fl_Group(490, 40, 285, 400);
	{
		// Create a new Fl_Choice widget to allow the changing of the wanted motor's type
		Fl_Choice * MotorOptions = new Fl_Choice(500, 50, 260, 25);

		// Add all currently supported Motor Types as individual options
		MotorOptions->add("No motor type selected");
		MotorOptions->add("Servo Motor");
		MotorOptions->add("Stepper Motor");
		MotorOptions->add("DC Motor");
		MotorOptions->add("Custom Motor");

		// Set the option to default to the no motor type selected option
		MotorOptions->value(0);

		// Add the MotorInterfaceChangeCaller function as the MotorOptions "button" functionality
		MotorOptions->callback(MotorInterfaceChangeCaller, (void *)this);
	}

	// 
	MotorDefault->end();
	MotorTabs->add(MotorDefault);

	// 
	MotorTabs->value(MotorDefault);

	// 
	if (MotorInfo.size() == 20) return;

	// 
	MotorInfo.push_back(new Fl_Button(395, (CallingWidget->y() + 30), 90, 25, "Add Motor"));
	MotorInfo[MotorInfo.size() - 1]->callback(AddMotorCaller, (void *)this);
	CurrentWindow->add(MotorInfo[MotorInfo.size() - 1]);
	MotorInfo[MotorInfo.size() - 1]->redraw();
}


// Function for allowing the call to the UpdateMotor function, due to FLTK function pointer calls
//     requiring the function to be static, but requiring non-static functionality from the
//     wanted function
void UserInterface::UpdateMotorCaller(Fl_Widget * CallingWidget, void * object) {
	((UserInterface*)object)->UpdateMotor(CallingWidget);
}


// Function for handling the need of updating the selected Fl_Tabs based on the clicked button
void UserInterface::UpdateMotor(Fl_Widget * CallingWidget) {
	// 
	int i = 0;
	for (i = 0; (MotorInfo.begin() + i) != MotorInfo.end(); ++i) {
		// 
		if (MotorInfo[i] == (Fl_Button *)CallingWidget) break;
	}

	MotorTabs->value(MotorTabs->child(i));
	MotorTabs->redraw();
}


// Function for allowing the call to the CreateMotorWindow function, due to FLTK function pointer
//     calls requiring the function to be static, but requiring non-static functionality from the
//     wanted function
void UserInterface::CallMotorWindowCreation(Fl_Widget * w, void * object) {
	((UserInterface*)object)->CreateMotorWindow(w);
}


// Function for handling the creation of the "Advanced Window" of the GUI
void UserInterface::CreateAdvancedWindow(Fl_Widget * w) {
	CreateInputDeviceWindow(w);
	CreateMotorWindow(w);
}


// Function for allowing the call to the CreateAdvancedWindow function, due to FLTK function pointer
//     calls requiring the function to be static, but requiring non-static functionality from the
//     wanted function
void UserInterface::CallAdvancedWindowCreation(Fl_Widget * w, void * object) {
	((UserInterface*)object)->CreateAdvancedWindow(w);
}


// Function for handling the start of the FLTK GUI interface
UserInterface * UserInterface::Run(int * ReturnValue, int argc, char ** argv) {
	CreateIntroWindow();
	GlobalWindow->end();
	GlobalWindow->show(argc, argv);
	//this->AddAnim({0, 0.4, CurrentWindow, 0, 0, 800, 400, 400, 200, 0, 0});
	//Fl::add_timeout(0.04, this->Player, this);
	(*ReturnValue) = Fl::run();
	return this;
}


/*******************************************************************************************************************************/
/*                                                                                                                             */
/*    Past this point is the start of all animation functionality that has been given up on due to time constraints. Sorry.    */
/*                                                                                                                             */
/*******************************************************************************************************************************/


// Function for ending all animations within the animation stack, i think
void UserInterface::EndAnims() {
	switch (AnimEndState) {
		case Transitions::Null :
		default:
			return;
	}
}


// Function for allowing the call to the AnimPlayback function, due to FLTK function pointer calls
//     requiring the function to be static, but requiring non-static functionality from the
//     wanted function
void UserInterface::Player(void * object) {
	((UserInterface*)object)->AnimPlayback();
}


// Function for playing all current animations within the animation stack
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


// Function for adding a new animation within the anim stack
void UserInterface::AddAnim(AnimData NewAnim) {
	Animations.push_back(NewAnim);
}


// Useless
void UserInterface::one() {
	// Creation and starting of the wanted tracker session
	*PointerToTracker = new TrackerSession(PointerToParams);
	(*PointerToTracker)->startTracking();
}


// Useless
void UserInterface::two(std::string CommandIn) {
	// Update session parameters
	//PointerToParams->UpdateSessionParameters(CommandIn);
}

