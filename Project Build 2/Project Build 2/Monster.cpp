#include "Monster.h"

const int Monster :: HP_START = 15;
const int Monster::  HP_PER_LEVEL = 4;

Monster:: Monster(std:: string name,int level) : Character(name,level)
{
	assignOtherAttributes();
	image = 'M';
}

Monster:: ~Monster()
{}

void Monster::levelUp()
{
	maxHP += HP_PER_LEVEL + modCon;
	curHP = maxHP;
	++level;
	for (size_t i = 0; i < baseAttackBonus.size(); i++)
	{
		baseAttackBonus[i] += 1;
	}
	if (level == 6 || level == 11 || level == 16)
	{
		baseAttackBonus.push_back(1);
	}
	recalculateAttributes();
}

void Monster::recalculateAttributes()
{
	//Plus inventory bonuses...
	effStr = baseStr;
	effDex = baseDex;
	effCon = baseCon;
	effInt = baseInt;
	effWis = baseWis;
	effCha = baseCha;

	modStr = calcModifier(effStr);
	modDex = calcModifier(effDex);
	modCon = calcModifier(effCon);
	modInt = calcModifier(effInt);
	modWis = calcModifier(effWis);
	modCha = calcModifier(effCha);

	meleeAttackBonus = modStr + static_cast<int>(Character::level / 2);
	meleeDmgBonus = modStr;
	ac = 10 + modDex;
}


