/*----------------------------------------------------------------------------*\
| UserInterface.cpp                                                            |
|                                                                              |
|                                                                              |
| Febuary 16, 2020      Created document framework.                            |
\*----------------------------------------------------------------------------*/

#ifndef _USER_INTERFACE_H_
#define _USER_INTERFACE_H_
#pragma once

// Include section, following as globals, FLTK, OpenCV, and, lastly, locals
#include <vector>
#include <cstdint>
#include <FL/Fl.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include "../SessionParameters.h"
#include "../TrackerSession.h"


// The user interface for the current program
class UserInterface {
public:
	// 
	UserInterface(SessionParameters * GlobalParams, TrackerSession ** GlobalTracker);

	// 
	~UserInterface();

	// Parses input from the UserInterface to run commands
	UserInterface * Run(int * ReturnValue, int argc, char **argv);

protected:
	// 
	struct AnimData {
		float AnimDeltaTime = 0;
		float WantedAnimTime = 1.0;
		Fl_Widget * AnimTarget = nullptr;
		int WantedX = 0;
		int WantedY = 0;
		int WantedWidth = 0;
		int WantedHeight = 0;
		int StarterX = 0;
		int StarterY = 0;
		int StarterWidth = 0;
		int StarterHeight = 0;
	};

	// 
	enum Transitions : uint8_t {
		Null = 0,
		ToInputDevice = 1,
		ToMotors = 2
	};

	// 
	std::vector<AnimData> Animations;
	Transitions AnimEndState = Transitions::Null;

	// 
	Fl_Window * GlobalWindow = nullptr;
	Fl_Group * CurrentWindow = nullptr;

	// 
	SessionParameters * PointerToParams;
	TrackerSession ** PointerToTracker;
	std::vector<std::string> deviceBuffer;

	// 
	Fl_Tabs * MotorTabs = nullptr;
	std::vector<Fl_Button *> MotorInfo;
	std::vector<std::string> buffer;

	// 
	void CreateIntroWindow();

	// 
	static void MotorInterfaceChangeCaller(Fl_Widget *, void *);

	// 
	void MotorInterfaceChange(Fl_Widget *);

	// 
	static void AddMotorCaller(Fl_Widget *, void *);

	// 
	void AddMotor(Fl_Widget *);

	// 
	static void UpdateMotorCaller(Fl_Widget *, void *);

	// 
	void UpdateMotor(Fl_Widget *);

	// 
	void CreateInputDeviceWindow(Fl_Widget *);

	// 
	static void CallInputWindowCreation(Fl_Widget *, void *);

	// 
	void CreateMotorWindow(Fl_Widget *);

	// 
	static void CallMotorWindowCreation(Fl_Widget *, void *);

	// 
	void CreateAdvancedWindow(Fl_Widget *);

	// 
	static void CallAdvancedWindowCreation(Fl_Widget *, void *);

	// 
	void EndAnims();

	// 
	static void Player(void *);

	// 
	void AnimPlayback(void);

	// 
	void AddAnim(AnimData);

	// 
	void one();

	// 
	void two(std::string);
};

#endif // _USER_INTERFACE_H_

