#include "Character.h"

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
	for (int i = 0; i < inv.size(); i++)
	{
		delete inv[i];
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
			unequip(7); //Unequips the second ring slot
			slot[7] = &item;
		}
		else
		{
			unequip( item.slot );
			slot[item.slot] = &item;
		}
	}
	else //Trying to equip a misc. item - Impossible
	{
		std::cout << "You cannot equip " << item.name << ".\n";
	}

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

}

//Useful method to print the Character to console... It should makea string and return it, but I haven't looked up the equivalent of
//a StringBuilder class in C++ yet...
void Character::characterSheet()
{
	std::cout << "Name: " << name << ", level: " << level << std::endl << std::endl
		<< "STR: " << effStr << " || " << modStr << std::endl
		<< "DEX: " << effDex << " || " << modDex << std::endl
		<< "CON: " << effCon << " || " << modCon << std::endl
		<< "INT: " << effInt << " || " << modInt << std::endl
		<< "WIS: " << effWis << " || " << modWis << std::endl
		<< "CHA: " << effCha << " || " << modCha << std::endl
		<< std::endl;

	printEquiped();

	std::cout << std::endl;

	printInv();

	std::cout << std::endl;

	std::cout << "HP: " << curHP << "/" << maxHP << std::endl;
	std::cout << "Armour Class: " << ac << std::endl;
	std::cout << "Attack Bonus: " << attackBonus << std::endl;
	std::cout << "Damage Bonus: " << dmgBonus << std::endl;

	std::cout << std::endl;

	std::cout << "Gold: " << gold << std::endl;
}

void Character::printEquiped()
{
	std::cout << "Currently wearing: " << std::endl;
	for (unsigned int i = 0; i < slot.size(); i++)
	{
		if( slot[i] != NULL)
		{
			std::cout << "\t" << slot[i]->name << std::endl;
		}
	}
}

void Character::printInv()
{
	std::cout << "Currently in inventory:" << std::endl;
	for (unsigned int i = 0; i < inv.size(); i++)
	{
		if( inv[i] != NULL )
		{
			std::cout << "\t" << inv[i]->name << std::endl;
		}

	}
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
