#include "Dice.h"

int roll(int sides, int numDice, int modifier)
{
	std::vector<int> results(numDice);
	for (int i = 0; i < numDice; i++)
	{
		results[i] = rand() % sides + 1;
	}

	int sum = 0;

	for (int i = 0; i < numDice; i++)
	{
		sum += results[i];
	}

	return sum + modifier;
}