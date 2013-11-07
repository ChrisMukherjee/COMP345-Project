#include "Character.h"

#include <sstream>
#include <fstream>

// **********PUBLIC MEMBER FUNCTIONS**********//

// Assign and initialize all the data members
Character::Character(std::string name, int level) :
	level(level),
	name(name)
{
	assignAbilityScores();
}

Character::~Character()
{
	for (size_t i = 0; i < inv.size(); i++)
	{
		delete inv.at(i);
	}
}

// Ringslot is defaulted to 1
void Character::equip(Equippable& item, int ringSlot)
{
	//Each thing you equip is also placed in inventory i.e. picked up
	pickUp(&item);

	//If it's a ring and you specify you want it in ringSlot 2, we do this special case
	if(item.getIType() == Equippable::ItemType::RING && ringSlot == 2)
	{
		if(slot[7] != NULL)
		{
			unequip(7); //Unequips the second ring slot
		}
		slot[7] = &item;
	}
	else
	{
		if(slot[item.getIType()] != NULL)
		{
			unequip( item.getIType() );
		}
		slot[item.getIType()] = &item;
	}
	//notify(); //This should be uncommented when we have a GUI
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
	//notify(); //This should be uncommented when we have a GUI
}

void Character::pickUp(Item* item)
{
	inv.push_back(item);
	//notify(); //This should be uncommented when we have a GUI
}

void Character::drop(Item* item)
{
	for (size_t i = 0; i < inv.size(); ++i)
	{
		if (item == inv[i])
		{
			inv.erase(inv.begin() + i);
			inv.shrink_to_fit();
			delete item;
			break; //Found the thing to delete, no need to keep iterating.
		}
	}
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
			sstm << "\t" << slot[i]->getName() << std::endl;
		}
	}

	return sstm.str();
}

std::string Character::invToString()
{
	std::stringstream sstm;

	sstm << "Currently in inventory:" << std::endl;
	for (size_t i = 0; i < inv.size(); i++)
	{
		if( inv[i] != NULL )
		{
			sstm << "\t" << inv[i]->getName() << std::endl;
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

bool Character::saveCharacter(std::string filename)
{
	std::ofstream f(filename, std::ios::out);

	if (f.is_open())
	{
		f << name << std::endl
			<< level << std::endl
			<< baseStr << std::endl
			<< baseDex << std::endl
			<< baseCon << std::endl
			<< baseInt << std::endl
			<< baseWis << std::endl
			<< baseCha << std::endl
			<< effStr << std::endl
			<< effDex << std::endl
			<< effCon << std::endl
			<< effInt << std::endl
			<< effWis << std::endl
			<< effCha << std::endl
			<< modStr << std::endl
			<< modDex << std::endl
			<< modCon << std::endl
			<< modInt << std::endl
			<< modWis << std::endl
			<< modCha << std::endl
			<< ac << std::endl
			<< attackBonus << std::endl
			<< dmgBonus << std::endl
			<< maxHP << std::endl
			<< curHP << std::endl
			<< gold << std::endl;
		f.close();
		return true;
	}
	else
	{
		return false;
	}
}

// Load a character from file
bool Character::loadCharacter(std::string filename)
{
	std::ifstream f(filename, std::ios::in);

	if (f.is_open())
	{
		f >> name;
		f >> level;
		f >> baseStr;
		f >> baseDex;
		f >> baseCon;
		f >> baseInt;
		f >> baseWis;
		f >> baseCha;
		f >> effStr;
		f >> effDex;
		f >> effCon;
		f >> effInt;
		f >> effWis;
		f >> effCha;
		f >> modStr;
		f >> modDex;
		f >> modCon;
		f >> modInt;
		f >> modWis;
		f >> modCha;
		f >> ac;
		f >> attackBonus;
		f >> dmgBonus;
		f >> maxHP;
		f >> curHP;
		f >> gold;
		f.close();
		return true;
	}
	else
	{
		return false;
	}
}

//**********PRIVATE MEMBER FUNCTIONS**********//

// Rolls 4d6 and chooses the best three rolls
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

// Based on DnD rules
int Character::calcModifier(int base)
{
	return static_cast<int>(floor((base - 10) / 2));
}

// Used by constructor to initialize and assign data members
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