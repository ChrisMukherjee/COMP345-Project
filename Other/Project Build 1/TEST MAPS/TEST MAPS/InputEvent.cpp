#include "InputEvent.h"


InputEvent::InputEvent(std::string name, int keyCode)
{
	this->name = name;
	this->keyCode = keyCode;
	down = false;
}