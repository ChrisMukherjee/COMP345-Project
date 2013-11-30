#pragma once

#include "character.h"

class Fighter : public Character
{
public:
	//Static constans related to hit points
	static const int HP_START;
	static const int HP_PER_LEVEL;

	//Constructor and destructor
	Fighter(std::string name = "Deafult Character", int level = 1);
	virtual ~Fighter();

	//Method to assign class (e.g. Fighter) specific data members
	virtual void assignOtherAttributes();
	virtual void levelUp();
};