#include <string>
#include "../inc/UserInterface.h"

void _test_UserInterfaceParseCommand(std::string CommandIn) {
	UserInterface ui;
	
	cout << ui.ParseCommand(CommandIn);
}

int main() {
	_test_UserInterfaceParseCommand("session");
	_test_UserInterfaceParseCommand("Session");
	_test_UserInterfaceParseCommand("");
	_test_UserInterfaceParseCommand(NULL);
	_test_UserInterfaceParseCommand("abcdefghijklmnopqrstuvwxyz1234567890-=[];',./`");
	
	std::string allChars;
	for (char c = 0; c <= 128; c++)
		allChars += c;
	_test_UserInterfaceParseCommand(allChars);
}