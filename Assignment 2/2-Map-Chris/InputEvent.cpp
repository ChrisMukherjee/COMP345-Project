#include "InputEvent.h"
using namespace std;

InputEvent::InputEvent(string name, int keyCode)
{
	this->name = name;
	this->keyCode = keyCode;
	down = false;
}