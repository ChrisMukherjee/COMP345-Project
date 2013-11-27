#pragma once
#include "fighterbuilder.h"
class NimbleFighterBuilder :
	public FighterBuilder
{
public:
	NimbleFighterBuilder(void) {}
	virtual ~NimbleFighterBuilder(void){}

	virtual void buildAbilityScores();
};

