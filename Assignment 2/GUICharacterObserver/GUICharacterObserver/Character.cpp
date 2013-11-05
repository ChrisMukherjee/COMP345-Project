#include "Character.h"

#include <sstream>

// **********PUBLIC MEMBER FUNCTIONS**********//

//Assign and initialize all the data members
Character::Character(std::string name, int level)
{
	Character::level = level;
	Character::name = name;

	assignAbilityScores();
}

Character::~Character()
{
	for (size_t i = 0; i < inv.size(); i++)
	{
		delete inv.at(i);
	}
}

//Ringslot is defaulted to 1
void Character::equip(Item& item, int ringSlot)
{
	//Make sure the item to be equiped is not a misc. item
	if(item.slot != Item::ItemSlot::MISC)
	{
		//Each thing you equip is also placed in inventory
		inv.push_back(&item);

		//If it's a ring and you specify you want it in ringSlot 2, we do this special case
		if(item.slot == Item::ItemSlot::RING && ringSlot == 2)
		{
			if(slot[7] != NULL)
			{
				unequip(7); //Unequips the second ring slot
			}
			slot[7] = &item;
		}
		else
		{
			if(slot[item.slot] != NULL)
			{
				unequip( item.slot );
			}
			slot[item.slot] = &item;
		}
	}
	else //Trying to equip a misc. item - Impossible
	{
		std::cout << "You cannot equip " << item.name << ".\n";
	}
	notify();
}

void Character::unequip(int slotToUnequip)
{
	//Can't unequip a misc
	if( !(slotToUnequip > 7 || slotToUnequip < 0) )
	{
		//If there is nothing in the slot, there's nothing to unequip!
		if(slot[slotToUnequip] != NULL)
		{
			slot[slotToUnequip] = NULL;
		}
	}
	notify();
}


std::string Character::characterSheetToString()
{
	std::stringstream sstm;

	sstm << attributesToString() << std::endl
		<< equipedToString() << std::endl
		<< invToString() << std::endl
		<< otherAttributesToString() << std::endl
		<< goldToString() << std::endl;

	return sstm.str();
}

std::string Character::attributesToString()
{
	std::stringstream sstm;

	sstm << "Name: " << name << ", level: " << level << std::endl << std::endl
		<< "STR: " << effStr << " || " << modStr << std::endl
		<< "DEX: " << effDex << " || " << modDex << std::endl
		<< "CON: " << effCon << " || " << modCon << std::endl
		<< "INT: " << effInt << " || " << modInt << std::endl
		<< "WIS: " << effWis << " || " << modWis << std::endl
		<< "CHA: " << effCha << " || " << modCha << std::endl;

	return sstm.str();
}


std::string Character::equipedToString()
{
	std::stringstream sstm;

	sstm << "Currently wearing: " << std::endl;
	for (size_t i = 0; i < slot.size(); i++)
	{
		if( slot[i] != NULL)
		{
			sstm << "\t" << slot[i]->name << std::endl;
		}
	}

	return sstm.str();
}

std::string Character::invToString()
{
	std::stringstream sstm;

    //sstm << "Currently in inventory:" << std::endl;
	for (size_t i = 0; i < inv.size(); i++)
	{
		if( inv[i] != NULL )
		{
            sstm << inv[i]->name << std::endl;
		}
	}

	return sstm.str();
}

std::string Character::otherAttributesToString()
{
	std::stringstream sstm;

	sstm << "HP: " << curHP << "/" << maxHP << std::endl
		<< "Armour Class: " << ac << std::endl
		<< "Attack Bonus: " << attackBonus << std::endl
		<< "Damage Bonus: " << dmgBonus << std::endl;

	return sstm.str();
}

std::string Character::goldToString()
{
	return "Gold: " + std::to_string(gold) + "\n";
}


//**********PRIVATE MEMBER FUNCTIONS**********//

//Rolls 4d6 and chooses the best three rolls
int Character::generateAbilityScore()
{
	int rolls[4];
	int smallestIndex = 0; //Index of the smallest roll
	int smallestVal = 24; //Biggest possible roll with 4d6
	int sum = 0;

	for(int i = 0; i < 4; i++)
	{
		rolls[i] = roll(6, 1, 0);
		if(rolls[i] < smallestVal)
		{
			smallestIndex = i;
			smallestVal = rolls[i];
		}
	}

	rolls[smallestIndex] = 0;

	for(int i = 0; i < 4; i++)
	{
		sum += rolls[i];
	}

	return sum;

}

//Based on DnD rules
int Character::calcModifier(int base)
{
	return static_cast<int>(floor((base - 10) / 2));
}

//Used by constructor to initialize and assign data members
void Character::assignAbilityScores()
{
	baseStr = effStr = generateAbilityScore();
	baseDex = effDex = generateAbilityScore();
	baseCon = effCon = generateAbilityScore();
	baseInt = effInt = generateAbilityScore();
	baseWis = effWis = generateAbilityScore();
	baseCha = effCha = generateAbilityScore();

	modStr = calcModifier(baseStr);
	modDex = calcModifier(baseDex);
	modCon = calcModifier(baseCon);
	modInt = calcModifier(baseInt);
	modWis = calcModifier(baseWis);
	modCha = calcModifier(baseCha);
}
