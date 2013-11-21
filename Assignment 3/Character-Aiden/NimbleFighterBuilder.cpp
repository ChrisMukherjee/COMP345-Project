#include "NimbleFighterBuilder.h"

#include <algorithm>


void NimbleFighterBuilder::buildAbilityScores()
{
	int scores[] = {
		product->baseStr,
		product->baseDex,
		product->baseCon,
		product->baseInt,
		product->baseWis,
		product->baseCha
	};
	std::sort(scores, scores + 6);
	std::reverse(scores, scores + 6);
	product->baseDex = scores[0];
	product->baseCon = scores[1];
	product->baseStr = scores[2];
	product->baseInt = scores[3];
	product->baseWis = scores[4];
	product->baseCha = scores[5];
	product->recalculateAttributes();
}