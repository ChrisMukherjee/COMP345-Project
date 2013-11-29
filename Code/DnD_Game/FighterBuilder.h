#pragma once

#include "Fighter.h"

class FighterBuilder
{
public:
	FighterBuilder() {}
	virtual ~FighterBuilder() {}

	Fighter* getFighter() {return product;}

	void createNewFighter() {product = new Fighter();}

	virtual void buildAbilityScores() = 0;

protected:
	Fighter* product;
};

