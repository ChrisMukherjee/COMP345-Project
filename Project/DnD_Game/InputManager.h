#pragma once

#include <string>
#include <vector>
#include "InputEvent.h"

class InputManager
{
public:
	~InputManager() {};

	static std::string getInput(std::vector<InputEvent>&);

private:
		InputManager() {};
};

