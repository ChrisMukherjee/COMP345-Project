#include "FighterDirector.h"

FighterDirector::FighterDirector(FighterBuilder* fb) :
	built(false)
{
	 this->fb = fb;
}

void FighterDirector::constructFighter()
{
	fb->createNewFighter();
	fb->buildAbilityScores();
	built = true;
}

Fighter* FighterDirector::getFighter()
{
	if (built) {
		return fb->getFighter();
	} else {
		return NULL;
	}
}