#include "Fighter.h"

const int Fighter::HP_START = 15;
const int Fighter::HP_PER_LEVEL = 6;

Fighter::Fighter(std::string name, int level) : Character(name, level)
{
	assignOtherAttributes();
	image = 'F';
}

Fighter::~Fighter()
{
}

void Fighter::assignOtherAttributes()
{
	curHP = maxHP = HP_START + ((level - 1) * HP_PER_LEVEL) + baseCon;

	ac = 10 + modDex;

	attackBonus = modStr + static_cast<int>(Character::level / 2);

	dmgBonus = modStr;

	slot = std::vector<Equippable*>(8);

	inv = std::vector<Item*>();

	gold = 0;
}

void Fighter::levelUp()
{
	maxHP += HP_PER_LEVEL;
	curHP = maxHP;
	effStr = ++baseStr;
	effDex = ++baseDex;
	effCon = ++baseCon;
	effInt = ++baseInt;
	effWis = ++baseWis;
	effCha = ++baseCha;

	modStr = calcModifier(effStr);
	modDex = calcModifier(effDex);
	modCon = calcModifier(effCon);
	modInt = calcModifier(effInt);
	modWis = calcModifier(effWis);
	modCha = calcModifier(effCha);

	level++;
}

