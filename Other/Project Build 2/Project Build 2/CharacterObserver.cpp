#include "CharacterObserver.h"

#include <iostream>

CharacterObserver::CharacterObserver()
{
	subject = NULL;
	name = "View " + std::to_string(serial);
	++serial;
}

CharacterObserver::CharacterObserver(Character& c)
{
	subject = &c;
	subject->attach(this);
	name = "View " + std::to_string(serial);
	++serial;
}


CharacterObserver::~CharacterObserver()
{
	if (subject != NULL)
	{
		subject->detach(this);
		subject = NULL;
	}
}

void CharacterObserver::update(Observable* o)
{
	if (subject == o)
	{
		system("CLS");
		std::cout << "**************** Character Sheet ****************" << std::endl
			<< subject->characterSheetToString();
	}
}

int CharacterObserver::serial = 0;