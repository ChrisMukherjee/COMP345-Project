#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Item.h"
#include <sstream>
using namespace std;


//STATIC MEMBERS

int Equippable::equipIDCTR = 1;


  //----------------------------\\
 //   GENERAL ITEM FUNCTIONS     \\
//--------------------------------\\

/* ACCESSORS */

string Item::getName()
{
	return name;
}

int Item::getItemID()
{
	return itemID;
}

bool Equippable::getEqStatus()
{
	return equipped;
}

Equippable::ItemType Equippable::getIType()
{
	return type;
}



/*ENCHANTMENT RELATED ACCESSORS*/

int Equippable::getArmBoost()
{
	return armboost;
}

int Equippable::getAtkBoost()
{
	return atkboost;
}

int Equippable::getChaBoost()
{
	return chaboost;
}

int Equippable::getConBoost()
{
	return conboost;
}

int Equippable::getDexBoost()
{
	return dexboost;
}

int Equippable::getDmgBoost()
{
	return dmgboost;
}

int Equippable::getIntBoost()
{
	return intboost;
}

int Equippable::getStrBoost()
{
	return strboost;
}

int Equippable::getWisBoost()
{
	return wisboost;
}

void Equippable::getAllEnchantments(Equippable eqp)
{
	ostringstream resultingString;
	if (eqp.getIType() == HELMET)
	{
		resultingString << eqp.getName() << endl;
		resultingString << "Enchantments: " << endl;
		resultingString << "------------" << endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << endl;
		}
		if (eqp.getIntBoost() > 0)
		{
			resultingString << "Intelligence: " << eqp.getIntBoost() << endl;
		}
		if (eqp.getWisBoost() > 0)
		{
			resultingString << "Wisdom: " << eqp.getWisBoost() << endl;
		}

		cout << resultingString.str();
	}

	else if (eqp.getIType() == ARMOR)
	{
		resultingString << eqp.getName() << endl;
		resultingString << "Enchantments: " << endl;
		resultingString << "------------" << endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << endl;
		}
		cout << resultingString.str();
	}

	else if (eqp.getIType() == SHIELD)
	{
		resultingString << eqp.getName() << endl;
		resultingString << "Enchantments: " << endl;
		resultingString << "------------" << endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << endl;
		}
		cout << resultingString.str();
	}

	else if (eqp.getIType() == RING)
	{
		resultingString << eqp.getName() << endl;
		resultingString << "Enchantments: " << endl;
		resultingString << "------------" << endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << endl;
		}
		if (eqp.getIntBoost() > 0)
		{
			resultingString << "Intelligence: " << eqp.getIntBoost() << endl;
		}
		if (eqp.getWisBoost() > 0)
		{
			resultingString << "Wisdom: " << eqp.getWisBoost() << endl;
		}
		cout << resultingString.str();
	}

	else if (eqp.getIType() == BELT)
	{
		resultingString << eqp.getName() << endl;
		resultingString << "Enchantments: " << endl;
		resultingString << "------------" << endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << endl;
		}
		if (eqp.getStrBoost() > 0)
		{
			resultingString << "Strength: " << eqp.getStrBoost() << endl;
		}
		if (eqp.getConBoost() > 0)
		{
			resultingString << "Constitution: " << eqp.getConBoost() << endl;
		}
		if (eqp.getWisBoost() > 0)
		{
			resultingString << "Wisdom: " << eqp.getWisBoost() << endl;
		}
		if (eqp.getChaBoost() > 0)
		{
			resultingString << "Charisma: " << eqp.getChaBoost() << endl;
		}
		cout << resultingString.str();
	}

	else if (eqp.getIType() == BOOTS)
	{
		resultingString << eqp.getName() << endl;
		resultingString << "Enchantments: " << endl;
		resultingString << "------------" << endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << endl;
		}
		if (eqp.getDexBoost() > 0)
		{
			resultingString << "Dexterity: " << eqp.getDexBoost() << endl;
		}

		cout << resultingString.str();
	}

	else if (eqp.getIType() == WEAPON)
	{
		resultingString << eqp.getName() << endl;
		resultingString << "Enchantments: " << endl;
		resultingString << "------------" << endl;
		if (eqp.getAtkBoost() > 0)
		{
			resultingString << "Attack: " << eqp.getAtkBoost() << endl;
		}
		if (eqp.getDmgBoost() > 0)
		{
			resultingString << "Damage: " << eqp.getDmgBoost() << endl;
		}
		cout << resultingString.str();
	}
	
}


/* MUTATORS */

void Item::setName(string nm)
{
	name = nm;
}

void Item::setItemID(int id)
{
	itemID = id;
}

void Equippable::setEqStatus(bool eq)
{
	equipped = eq;
}

void Equippable::setIType(ItemType ityp)
{
	type = ityp;
}

/* ENCHANTMENT SPECIFIC MUTATORS */

void Equippable::setArmBoost(int arbst)
{
	if (arbst < 0 || arbst > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		armboost = arbst;	
}

void Equippable::setAtkBoost(int atbst)
{
	if (atbst < 0 || atbst > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		atkboost = atbst;
}

void Equippable::setChaBoost(int chbst)
{
	if (chbst < 0 || chbst > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		chaboost = chbst;
}

void Equippable::setConBoost(int cobst)
{
	if (cobst < 0 || cobst > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		conboost = cobst;
}

void Equippable::setDexBoost(int debst)
{
	if (debst < 0 || debst > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		dexboost = debst;
}

void Equippable::setDmgBoost(int dmbst)
{
	if (dmbst < 0 || dmbst > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		dmgboost = dmbst;
}

void Equippable::setIntBoost(int ibst)
{
	if (ibst < 0 || ibst > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		intboost = ibst;
}

void Equippable::setStrBoost(int sbst)
{
	if (sbst < 0 || sbst > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		strboost = sbst;
}

void Equippable::setWisBoost(int wbst)
{
	if (wbst < 0 || wbst > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		wisboost = wbst;
}

Equippable::Equippable(ItemType itype, int level)
{
	int chance = level * 5;
	cout << "Generating equippable item..." << endl;
	cout << endl;
	setIType(itype);
	setItemID(equipIDCTR++);
	//cout << nm << endl;
	cout << "Equip ID: " << getItemID() << endl;

	int chanceRoll;

	if (itype == HELMET)
	{
		//INTELLIGENCE
		setName("Helmet");
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setIntBoost(0);
		else 
		{
			setIntBoost(roll(5));
			setName(getName() + ", +" + std::to_string(intboost) + " intelligence");
		}

		//WISDOM
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setWisBoost(0);
		else 
			setWisBoost(roll(5));

		//ARMOR CLASS
		armboost = 1;
	}

	else if (itype == ARMOR)
	{
		int type = rand() % 8;
		mat = static_cast<Equippable::ArmorMaterial>(type);
		armboost = type + 1;
	}

	else if (itype == SHIELD)
	{
		int type = rand() % 3;
		sType = static_cast<Equippable::ShieldType>(type);
		armboost = type + 1;
	}

	else if (itype == RING)
	{
		//ARMOR CLASS
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setArmBoost(0);
		else 
			setArmBoost(roll(5));

		//STRENGTH
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setStrBoost(0);
		else 
			setStrBoost(roll(5));

		//CONSTITUTION
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setConBoost(0);
		else 
			setConBoost(roll(5));

		//WISDOM
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setWisBoost(0);
		else 
			setWisBoost(roll(5));

		//CHARISMA
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setChaBoost(0);
		else 
			setChaBoost(roll(5));
	}

	else if (itype == BELT)
	{
		//CONSTITUTION
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setConBoost(0);
		else 
			setConBoost(roll(5));

		//STRENGTH
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setStrBoost(0);
		else 
			setStrBoost(roll(5));
	}

	else if (itype == BOOTS)
	{
		//ARMOR CLASS
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setArmBoost(0);
		else 
			setArmBoost(roll(5));

		//DEXTERITY
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setDexBoost(0);
		else 
			setDexBoost(roll(5));
	}

	else if (itype == WEAPON)
	{
		//ATTACK
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setAtkBoost(0);
		else 
			setAtkBoost(roll(5));

		//DAMAGE
		chanceRoll = rand() % 100 + 1;
		if (chanceRoll <= chance)
			setDmgBoost(0);
		else 
			setDmgBoost(roll(5));
	}
};


//------------CONTAINER CLASS-------------------//

Container::Container(string nm)
{
	cout << "Generating a Container... " << nm << endl;
	setName(nm);

	vector<Equippable> containervector;
}

void Container::addEQtoContainer(Equippable eqp)
{
	cout << "Inserting " << eqp.getName() << " to " << Container::getName() << "." << endl;
	containervector.push_back(eqp);

	notify();

};

//void Container::addCOtoBP(Consumable cns){};

void Container::remEQfromContainer(int id)
{
	

	int remCTR = 0;

	for (size_t i = 0; i < containervector.size(); i++)
	{
		if (containervector[i].getItemID() == id)
		{
			cout << "Removing " << containervector[i].getName() << " from " << Container::getName() << "." << endl;
			containervector.erase(containervector.begin() + i);
			remCTR++;
		}
		if (remCTR != 0)
			break;
	}
	//cout << "NOT BROKEN YET. PAUSING..." << endl;
	//system("pause");
	notify();
}

Equippable Container::getEQfromContainer(int id)
{
	int getCTR = 0;

	for (size_t i = 0; i < containervector.size(); i++)
	{
		if (containervector[i].getItemID() == id)
		{
			return containervector[i];
			getCTR++;
		}
		
		if (getCTR != 0)
			break;
	}
}

string Container::output()
{
	ostringstream streamer;

	if (containervector.size() != 0)
	{
		//cout << "CONTAINER VECTOR SIZE IS NOT 0" << endl;
		for (size_t i = 0; i < containervector.size(); i++)
		{
			streamer << ": " << containervector[i].getName() << " :" << endl;
			//cout << "ITERATING THROUGH VECTOR TO OUTPUT ITEMS" << endl;
		}
		return streamer.str();
	}

	else
		return Container::getName() + " is empty.\n";
}