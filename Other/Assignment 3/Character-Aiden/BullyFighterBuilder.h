#pragma once
#include "fighterbuilder.h"
class BullyFighterBuilder :
	public FighterBuilder
{
public:
	BullyFighterBuilder(void) {}
	virtual ~BullyFighterBuilder(void) {}

	virtual void buildAbilityScores();
};

