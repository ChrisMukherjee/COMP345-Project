#pragma once

#include <string>
#include <vector>
#include "InputEvent.h"
using namespace std;

class InputManager
{
public:
	~InputManager() {};
	static string getInput(std::vector<InputEvent>&);

private:
		InputManager() {};
};

