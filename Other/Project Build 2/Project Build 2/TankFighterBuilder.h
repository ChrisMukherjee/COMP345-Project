#pragma once
#include "fighterbuilder.h"
class TankFighterBuilder :
	public FighterBuilder
{
public:
	TankFighterBuilder(void) {}
	virtual ~TankFighterBuilder(void) {}

	void virtual buildAbilityScores();
};

