#pragma once

#include "Character.h"

class Monster : public Character
{
public:
	//Static constants related to hit points
	static const int HP_START;
	static const int HP_PER_LEVEL;

	//Constructor and destructor
	Monster(std::string name = "Default Monster", int level = 1);
	virtual ~Monster();

	//Method to assign class (e.g. Fighter) specific data members
	virtual void assignOtherAttributes();
	virtual void levelUp();
	virtual void recalculateAttributes();
};

