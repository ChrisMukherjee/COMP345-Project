#pragma once

#include "FighterBuilder.h"

class FighterDirector
{
public:
	FighterDirector(FighterBuilder* fb = NULL);
	~FighterDirector(void) {}

	void setFighterBuilder(FighterBuilder* fb) {this->fb = fb;}
	void constructFighter();

	Fighter* getFighter(); 

private:
	FighterBuilder* fb;
	bool built;
};

