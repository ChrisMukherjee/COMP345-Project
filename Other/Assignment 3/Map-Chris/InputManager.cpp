#include "InputManager.h"
#include "windows.h"
using namespace std;

string InputManager::getInput(vector<InputEvent>& events)
{
	while (true)
	{
		for (size_t i = 0; i < events.size(); ++i)
		{
			if (GetAsyncKeyState(events[i].getKeyCode()))
			{
				if (!events[i].isDown())
				{
					events[i].setDown(true);
					return events[i].getName();
				}
			}
			else
			{
				events[i].setDown(false);
			}
		}
	}
}
