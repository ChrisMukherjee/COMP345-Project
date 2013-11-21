#pragma once

#include <string>
using namespace std;

class InputEvent {
public:
	InputEvent(string name, int keyCode);
	~InputEvent() {};
	string getName() {return name;}
	int getKeyCode() {return keyCode;}
	bool isDown() {return down;}
	void setDown(bool b) {down = b;}

private:
	string name;
	int keyCode;
	bool down;
};

