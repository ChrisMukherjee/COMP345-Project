#pragma once

#include <string>

class InputEvent
{
public:
	InputEvent(std::string name, int keyCode);
	~InputEvent() {};

	std::string getName() {return name;}
	int getKeyCode() {return keyCode;}
	bool isDown() {return down;}

	void setDown(bool b) {down = b;}

private:
	std::string name;
	int keyCode;
	bool down;
};

