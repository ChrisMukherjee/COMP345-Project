#include "Fighter.h"

const int Fighter::HP_START = 15;
const int Fighter::HP_PER_LEVEL = 6;

Fighter::Fighter(std::string name, int level) : Character(name, level)
{
	assignOtherAttributes();
	image = 'F';
    recalculateAttributes();
}

Fighter::~Fighter()
{
}

void Fighter::assignOtherAttributes()
{
	curHP = maxHP = HP_START + ((level - 1) * HP_PER_LEVEL) + baseCon;

	ac = 10 + modDex;

	meleeAttackBonus = modStr + static_cast<int>(Character::level / 2);

	meleeDmgBonus = modStr;

    slot = std::vector<Equippable*>(8);

	inv = std::vector<Equippable*>();

	gold = 0;
}

void Fighter::levelUp()
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

void Fighter::recalculateAttributes()
{
    meleeDmgBonus = 0;
    ac = 10;
    int attackBonusPerAttack = 0;
    effStr = baseStr;
    effDex = baseDex;
    effCon = baseCon;
    effInt = baseInt;
    effWis = baseWis;
    effCha = baseCha;
    for (size_t i = 0; i < slot.size(); i++)
    {
        if (slot[i] != NULL)
        {
            effStr += slot[i]->getStrBoost();
            effDex += slot[i]->getDexBoost();
            effCon += slot[i]->getConBoost();
            effInt += slot[i]->getIntBoost();
            effWis += slot[i]->getWisBoost();
            effCha += slot[i]->getChaBoost();
            meleeDmgBonus += slot[i]->getDmgBoost();
            ac += slot[i]->getArmBoost();
            attackBonusPerAttack += slot[i]->getAtkBoost();
        }
    }
    attackBonus.clear();
    for (size_t i = 0; i < baseAttackBonus.size(); i++)
    {
        attackBonus.push_back(baseAttackBonus[i]);
    }
    for (size_t i = 0; i < baseAttackBonus.size(); i++)
    {
        attackBonus[i] += attackBonusPerAttack;
    }

    modStr = calcModifier(effStr);
    modDex = calcModifier(effDex);
    modCon = calcModifier(effCon);
    modInt = calcModifier(effInt);
    modWis = calcModifier(effWis);
    modCha = calcModifier(effCha);

//    //meleeAttackBonus = modStr + static_cast<int>(Character::level / 2);

    meleeDmgBonus += modStr;
    ac += modDex;
}
