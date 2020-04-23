/*----------------------------------------------------------------------------*\
| UserInterface.cpp                                                            |
|                                                                              |
|                                                                              |
| Made: Febuary 16th, 2020           Created document framework.               |
| Last update: April 23rd, 2020      Updated all comments for clarity.         |
\*----------------------------------------------------------------------------*/

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include <iostream>                                    // For debugging purposes only
#include <string>                                      // For string class
#include <FL/Fl_Box.H>                                 // For Fl_Box class
#include <FL/Fl_Choice.H>                              // For Fl_Choice class
#include <FL/Fl_Simple_Counter.H>                      // For Fl_Simple_Counter class
#include <FL/Fl_PNG_Image.H>                           // For Fl_PNG_Image class
#include "opencv2/opencv.hpp"                          // I do not believe is needed
#include "../../Headers/UserInterface/UserInterface.h" // Self include
#include "../../Headers/SessionParameters.h"           // For SessionParameters class
#include "../../Headers/TrackerSession.h"              // For TrackerSession class
#include "../../Headers/HardwareInputs/InputDevice.h"  // For InputDevice class
#include "../../Headers/HardwareInputs/Camera.h"       // For Camera class
#include "../../Headers/HardwareInputs/Microphone.h"   // For Microphone class


// Constructor for the UserInterface class
UserInterface::UserInterface(SessionParameters * GlobalParams, TrackerSession ** GlobalTracker) {
	// Local pointers to global variables as to avoid the use of actual globals
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
	// Create the main OS window, along with the internal window
	GlobalWindow = new Fl_Window(360, 125, "Tracker System");
	CurrentWindow = new Fl_Group(0, 0, 360, 125);

	// Set default background colors of the two windows
	GlobalWindow->color(FL_DARK2);
	CurrentWindow->color(FL_DARK2);

	// Add the CurrentWindow into the GlobalWindow so that it is displayed
	GlobalWindow->add(CurrentWindow);
	GlobalWindow->resizable(CurrentWindow);

	// Create and add text to the CurrentWindow as to signify to the user the main functionality
	//     of the current window
	Fl_Box * InfoText = new Fl_Box(20, 10, 320, 25, "Select Tracker System Input Device Type");
	CurrentWindow->add(InfoText);

	// Add button for creating a camera type input device option, along with adding the proper
	//     callback function to the button for creating the input device window upon being clicked
	Fl_Button * CamButton = new Fl_Button(20, 40, 150, 35, "Camera");
	CamButton->callback(CallInputWindowCreation, (void *)this);
	CurrentWindow->add(CamButton);

	// Add button for creating a microphone type input device option, along with adding the proper
	//     callback function to the button for creating the input device window upon being clicked
	//     CURRENTLY DISABLED DUE TO A LACK OF IMPLEMENTATION TIME
	Fl_Button * MicButton = new Fl_Button(190, 40, 150, 35, "Microphone");
	//MicButton->callback((Fl_Callback*)CallInputWindowCreation, this);
	CurrentWindow->add(MicButton);

	// Add button for skipping all step by step setup functionality and skipping to the final "advanced"
	//     window, along with adding the proper callback function to the button for creating the advanced
	//     window upon being clicked
	Fl_Button * AdvancedButton = new Fl_Button(20, 80, 320, 35, "Click Here to skip to advanced mode");
	AdvancedButton->callback((Fl_Callback*)CallAdvancedWindowCreation, (void *)this);
	AdvancedButton->down_box(FL_NO_BOX); // Make the button hidden, so that the option doesn't pop
	CurrentWindow->add(AdvancedButton);
}


// Function for the creation of the input device specific handling side of the application's window
void UserInterface::CreateInputDeviceWindow(Fl_Widget * w) {
	// Resize the global and internal windows into the wanted input device window size
	GlobalWindow->resizable(nullptr);
	GlobalWindow->size(400, 650);
	CurrentWindow->resizable(nullptr);
	CurrentWindow->size(400, 650);
	GlobalWindow->resizable(CurrentWindow);

	// Create a local variable for checking whether the camera or microphone button was pressed
	bool IsMicrophone = false;

	// Loop through all objects added to the internal window
	for (int i = 0; i < CurrentWindow->children(); ++i) {

		// Get button that was pressed
		if (CurrentWindow->child(i)->changed()) {

			// If the button says "Camera", then the user wants a camera
			if (CurrentWindow->child(i)->label() == "Camera") {
				IsMicrophone = false;

			// If the button says "Microphone", then the user wants a microphone
			} else if (CurrentWindow->child(i)->label() == "Microphone") {
				IsMicrophone = true;
			}
		}
	} // If the advanced button was pressed, it defaults to a camera

	// Erase everything currently within the internal window
	CurrentWindow->clear();

	// Add a button for swapping to the other supported input device type; currently disabled
	Fl_Button * SwapButton = new Fl_Button(20, 10, (IsMicrophone ? 140 : 160), 25, (IsMicrophone ? "Swap To Camera" : "Swap To Microphone"));
	CurrentWindow->add(SwapButton);

	// Create a new text on the screen to inform the user which input device type is currently active
	Fl_Box * InfoText = new Fl_Box(250, 10, 140, 25, (IsMicrophone ? "Microphone" : "Camera"));
	InfoText->align(FL_ALIGN_LEFT);
	CurrentWindow->add(InfoText);

	// If the input device is a camera...
	if (!IsMicrophone) {
		// Add text for informing the user of what the next functionality does
		Fl_Box * SharpenText = new Fl_Box(155, 347, 140, 25, "Sharpened Image:");
		SharpenText->align(FL_ALIGN_LEFT);
		CurrentWindow->add(SharpenText);

		// Create a new choice box, also known as a combo box, for the sharpening amount
		Fl_Choice * SharpenOptions = new Fl_Choice(160, 345, 220, 25);

		// Add all currently supported Motor Types as individual options
		SharpenOptions->add("No sharpening");
		SharpenOptions->add("Light sharpening");
		SharpenOptions->add("Medium sharpening");
		SharpenOptions->add("Heavy sharpening");

		// Set the option to default to the no motor type selected option
		SharpenOptions->value(0);

		// Add function for camera sharpening filters; currently disabled
		//SharpenOptions->callback(nullptr);

		// Add the sharpening functionality to the internal window
		CurrentWindow->add(SharpenOptions);
		
		// Create a new camera and store it within the SessionParameters class
		PointerToParams->CurrentDevice = new Cam::Camera();
	}

	// Else, if the input device is a microphone...
	else {
		// Exit the program, since microphones are not supported as of now
		exit(0);
		//PointerToParams->CurrentDevice = new Mic::Microphone();

	// Create a new pointer to input device data based off the device, with the camera
	//     defaulting to the first found input device, and the microphone being a null pointer
	void * InputData = ((PointerToParams->CurrentDevice != nullptr) ? PointerToParams->CurrentDevice->GetValue(0) : nullptr);

	// If the input data pointer is NOT a null pointer...
	if (InputData != nullptr) {
		// If the device is a microphone, hard exit the code
		if (IsMicrophone) {
			exit(0);
			
		// Else, if the device is a camera...
		} else {
			// Create a new box for the camera image to display in and
			//     add it to the internal window
			Fl_Box * CameraImage = new Fl_Box(20, 40, 360, 260);
			CurrentWindow->add(CameraImage);
			
			// Draw the image from the input device's data after being converted
			//     into an Fl_RGB_Image class and being scaled to the wanted size
			CameraImage->image(((Fl_RGB_Image*)InputData)->copy(360, 260));
			CameraImage->redraw();
			
			// Create a new box for the sharpened camera image to display in
			//     and add it to the internal window
			Fl_Box * NewCameraImage = new Fl_Box(20, 375, 360, 260);
			CurrentWindow->add(NewCameraImage);
			
			// Draw the image from the input device's data after being sharpened,
			//     converted into an Fl_RGB_Image class, and being scaled to the
			//     wanted size
			// Apply sharpening here
			NewCameraImage->image(((Fl_RGB_Image*)InputData)->copy(360, 260));
			NewCameraImage->redraw();
		}
	}

	// Create a new choice/combo box for the current device selection
	Fl_Choice * CameraOptions = new Fl_Choice(20, 305, 220, 25);

	// If the device amount is greater than one (at least one device exists)...
	if (PointerToParams->CurrentDevice->GetDeviceAmount() >= 1) {

		// Loop through the devices and add new options within the choice/combo box for
		//     them, giving them names along the way
		for (int i = 0; i < PointerToParams->CurrentDevice->GetDeviceAmount(); ++i) {
			deviceBuffer.at(i) = "Device " + std::to_string(i);
			CameraOptions->add(deviceBuffer.at(i).c_str(), 0, nullptr);
		}

	// Else, if there are no devices attached...
	} else {
		// Create a generic button to inform the user of the information
		CameraOptions->add("No devices available");
		CameraOptions->value(0);
	}

	// Add the new choice/combo box to the internal window
	CurrentWindow->add(CameraOptions);
		
	// Create a new button for siwtching to the motors part of the GUI
	Fl_Button * MotorsButton = new Fl_Button(245, 305, 135, 25, "To Motors");
	CurrentWindow->add(MotorsButton);

	// Add the function callback for the motors GUI switch button
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
	// Resize the global and internal windows into the wanted motor window size
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

	// Add an empty motor type button as the default to both the motor array and the
	//     internal window
	MotorInfo.push_back(new Fl_Button(395, 40, 90, 25, "Motor 1"));
	MotorInfo[0]->callback(UpdateMotorCaller, (void *)this);
	CurrentWindow->add(MotorInfo[0]);

	// Add an add motor button to both the motor array and the internal window
	MotorInfo.push_back(new Fl_Button(395, 70, 90, 25, "Add Motor"));
	MotorInfo[1]->callback(AddMotorCaller, (void *)this);
	CurrentWindow->add(MotorInfo[1]);

	// Create and add new text to inform the user of functionality
	Fl_Box * InfoText = new Fl_Box(475, 10, 80, 25, "Motor Information:");
	CurrentWindow->add(InfoText);

	// Add a new hidden motor tab graphic
	MotorTabs = new Fl_Tabs(490, 40, 285, 460);
	{
		// Create a default motor group
		Fl_Group * MotorDefault = new Fl_Group(490, 40, 285, 460);
		{
			// Create a choice/combo box for the motor type options
			Fl_Choice * MotorOptions = new Fl_Choice(500, 50, 260, 25);

			// Add all currently supported Motor Types as individual options
			MotorOptions->add("No motor type selected");
			MotorOptions->add("Servo Motor");
			MotorOptions->add("Stepper Motor");
			MotorOptions->add("DC Motor");
			MotorOptions->add("Custom Motor");

			// Set the option to default to the no motor type selected option
			MotorOptions->value(0);

			// Add the proper function callback to the combo box
			MotorOptions->callback(MotorInterfaceChangeCaller, (void *)this);

		}
		MotorDefault->end(); // End filling the default motor group
	}
	MotorTabs->end(); // End filling the motor tab and add it to the internal window
	CurrentWindow->add(MotorTabs);

	// Add a new button for starting the tracker session 
	Fl_Button * TrackerStartButton = new Fl_Button(600, 610, 180, 25, "Start Tracking Session");
	CurrentWindow->add(TrackerStartButton);
	// TrackerStartButton->callback(/*TrackerStartCaller*/, (void *)this);
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
	// Update the new motor button to be a new motor with the proper function
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

	// End the pin creation and add the new pin type to the MotorTabs array
	MotorDefault->end();
	MotorTabs->add(MotorDefault);

	// Set the new current tab to be that of the newly created motor
	MotorTabs->value(MotorDefault);

	// If too many motors, do not add any more and exit
	if (MotorInfo.size() == 20) return;

	// Add a new "Add Motor" button with proper functionality
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
	// Create a local counter variable
	int i = 0;
	
	// Loop through all currently existing motors
	for (i = 0; (MotorInfo.begin() + i) != MotorInfo.end(); ++i) {
		// If the current motor is the one pressed, then exit the loop
		if (MotorInfo[i] == (Fl_Button *)CallingWidget) break;
	}

	// Set the current motor tab to the newly selected motor adn redraw the motor tabs
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
	// Create the input device part of the window with default settings
	CreateInputDeviceWindow(w);
	
	// Create the motor part of the window with default settings
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
	// Create the introduction window and setup the main OS-based external window
	CreateIntroWindow();
	GlobalWindow->end();
	GlobalWindow->show(argc, argv);
	
	// Dropped functionality for adding an animation as to pretty up everything
	//this->AddAnim({0, 0.4, CurrentWindow, 0, 0, 800, 400, 400, 200, 0, 0});
	//Fl::add_timeout(0.04, this->Player, this);
	
	// Start the program, making sure that the error code that the GUI returns upon destruction
	//     is returned to the main function for error printing, returning a pointer to the current
	//     UserInterface class upon destruction as well
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

