#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Item.h"
#include <sstream>



//STATIC MEMBERS

int Equippable::equipIDCTR = 1000;


//----------------------------\\
  /* GENERAL ITEM FUNCTIONS */
//-----------------------------\\

/* ACCESSORS */

std::string Item::getName()
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

Equippable::ArmorType Equippable::getArmType()
{
	if (type = ARMOR)
		return armtype;
}

Equippable::ShieldType Equippable::getShType()
{
	if (type = SHIELD)
		return shtype;
}

/*INHERENT ARMOR AND SHIELD MODIFIER ACCESSORS AND MUTATORS*/

int Equippable::getArmMod()
{
	if (type = ARMOR)
		return armormod;
}

void Equippable::setArmMod(int armmd)
{
	if (type = ARMOR)
		armormod = armmd;
}

int Equippable::getShMod()
{
	if (type = SHIELD)
		return shieldmod;
}

void Equippable::setShMod(int shmd)
{
	if (type = SHIELD)
		shieldmod = shmd;
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

std::string Equippable::getAllEnchantments(Equippable eqp)
{
	std::ostringstream resultingString;
	if (eqp.getIType() == HELMET)
	{
		resultingString << eqp.getName() << std::endl;
		resultingString << "Enchantments: " << std::endl;
		resultingString << "------------" << std::endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << std::endl;
		}
		if (eqp.getIntBoost() > 0)
		{
			resultingString << "Intelligence: " << eqp.getIntBoost() << std::endl;
		}
		if (eqp.getWisBoost() > 0)
		{
			resultingString << "Wisdom: " << eqp.getWisBoost() << std::endl;
		}

		return resultingString.str();
	}

	else if (eqp.getIType() == ARMOR)
	{
		resultingString << eqp.getName() << std::endl;
		resultingString << "Enchantments: " << std::endl;
		resultingString << "------------" << std::endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << std::endl;
		}
		return resultingString.str();
	}

	else if (eqp.getIType() == BRACERS)
	{
		resultingString << eqp.getName() << std::endl;
		resultingString << "Enchantments: " << std::endl;
		resultingString << "------------" << std::endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << std::endl;
		}
		if (eqp.getStrBoost() > 0)
		{
			resultingString << "Strength: " << eqp.getStrBoost() << std::endl;
		}
		return resultingString.str();
	}

	else if (eqp.getIType() == SHIELD)
	{
		resultingString << eqp.getName() << std::endl;
		resultingString << "Enchantments: " << std::endl;
		resultingString << "------------" << std::endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << std::endl;
		}
		return resultingString.str();
	}

	else if (eqp.getIType() == RING)
	{
		resultingString << eqp.getName() << std::endl;
		resultingString << "Enchantments: " << std::endl;
		resultingString << "------------" << std::endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << std::endl;
		}
		if (eqp.getIntBoost() > 0)
		{
			resultingString << "Intelligence: " << eqp.getIntBoost() << std::endl;
		}
		if (eqp.getWisBoost() > 0)
		{
			resultingString << "Wisdom: " << eqp.getWisBoost() << std::endl;
		}
		return resultingString.str();
	}

	else if (eqp.getIType() == BELT)
	{
		resultingString << eqp.getName() << std::endl;
		resultingString << "Enchantments: " << std::endl;
		resultingString << "------------" << std::endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << std::endl;
		}
		if (eqp.getStrBoost() > 0)
		{
			resultingString << "Strength: " << eqp.getStrBoost() << std::endl;
		}
		if (eqp.getConBoost() > 0)
		{
			resultingString << "Constitution: " << eqp.getConBoost() << std::endl;
		}
		if (eqp.getWisBoost() > 0)
		{
			resultingString << "Wisdom: " << eqp.getWisBoost() << std::endl;
		}
		if (eqp.getChaBoost() > 0)
		{
			resultingString << "Charisma: " << eqp.getChaBoost() << std::endl;
		}
		return resultingString.str();
	}

	else if (eqp.getIType() == BOOTS)
	{
		resultingString << eqp.getName() << std::endl;
		resultingString << "Enchantments: " << std::endl;
		resultingString << "------------" << std::endl;
		if (eqp.getArmBoost() > 0)
		{
			resultingString << "Armor: " << eqp.getArmBoost() << std::endl;
		}
		if (eqp.getDexBoost() > 0)
		{
			resultingString << "Dexterity: " << eqp.getDexBoost() << std::endl;
		}

		return resultingString.str();
	}

	else if (eqp.getIType() == SWORD)
	{
		resultingString << eqp.getName() << std::endl;
		resultingString << "Enchantments: " << std::endl;
		resultingString << "------------" << std::endl;
		if (eqp.getAtkBoost() > 0)
		{
			resultingString << "Attack: " << eqp.getAtkBoost() << std::endl;
		}
		if (eqp.getDmgBoost() > 0)
		{
			resultingString << "Damage: " << eqp.getDmgBoost() << std::endl;
		}
		return resultingString.str();
	}

	else if (eqp.getIType() == BOW)
	{
		resultingString << eqp.getName() << std::endl;
		resultingString << "Enchantments: " << std::endl;
		resultingString << "------------" << std::endl;
		if (eqp.getAtkBoost() > 0)
		{
			resultingString << "Attack: " << eqp.getAtkBoost() << std::endl;
		}
		if (eqp.getDmgBoost() > 0)
		{
			resultingString << "Damage: " << eqp.getDmgBoost() << std::endl;
		}
		return resultingString.str();
	}
	
}


/* MUTATORS */

void Item::setName(std::string nm)
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

void Equippable::setArmType(ArmorType artyp)
{
	if (type = ARMOR)
	{
		armtype = artyp;
		if (artyp == NADEF)
			setArmMod(0);
		else if (artyp == PADDED)
			setArmMod(1);
		else if (artyp == LEATHER)
			setArmMod(2);
		else if (artyp == STUDDEDLEATHER)
			setArmMod(3);
		else if (artyp == CHAINSHIRT)
			setArmMod(4);
		else if (artyp == BREASTPLATE)
			setArmMod(5);
		else if (artyp == BANDEDMAIL)
			setArmMod(6);
		else if (artyp == HALFPLATE)
			setArmMod(7);
		else if (artyp == FULLPLATE)
			setArmMod(8);
	}
}

void Equippable::setShType(ShieldType shtyp)
{
	if (type = SHIELD)
	{
		shtype = shtyp;
		if (shtyp == NSDEF)
			setShMod(0);
		else if (shtyp == BUCKLER)
			setShMod(1);
		else if (shtyp == HEAVYSHIELD)
			setShMod(2);
		else if (shtyp == TOWERSHIELD)
			setShMod(4);
	}
}

/* ENCHANTMENT SPECIFIC MUTATORS */

void Equippable::setArmBoost(int arbst)
{
	if (arbst < 0 || arbst > 5)
		std::cout << "Can only buff with values between 0 and 5, inclusively." << std::endl;
	else
		armboost = arbst;	
}

void Equippable::setAtkBoost(int atbst)
{
	if (atbst < 0 || atbst > 5)
		std::cout << "Can only buff with values between 0 and 5, inclusively." << std::endl;
	else
		atkboost = atbst;
}

void Equippable::setChaBoost(int chbst)
{
	if (chbst < 0 || chbst > 5)
		std::cout << "Can only buff with values between 0 and 5, inclusively." << std::endl;
	else
		chaboost = chbst;
}

void Equippable::setConBoost(int cobst)
{
	if (cobst < 0 || cobst > 5)
		std::cout << "Can only buff with values between 0 and 5, inclusively." << std::endl;
	else
		conboost = cobst;
}

void Equippable::setDexBoost(int debst)
{
	if (debst < 0 || debst > 5)
		std::cout << "Can only buff with values between 0 and 5, inclusively." << std::endl;
	else
		dexboost = debst;
}

void Equippable::setDmgBoost(int dmbst)
{
	if (dmbst < 0 || dmbst > 5)
		std::cout << "Can only buff with values between 0 and 5, inclusively." << std::endl;
	else
		dmgboost = dmbst;
}

void Equippable::setIntBoost(int ibst)
{
	if (ibst < 0 || ibst > 5)
		std::cout << "Can only buff with values between 0 and 5, inclusively." << std::endl;
	else
		intboost = ibst;
}

void Equippable::setStrBoost(int sbst)
{
	if (sbst < 0 || sbst > 5)
		std::cout << "Can only buff with values between 0 and 5, inclusively." << std::endl;
	else
		strboost = sbst;
}

void Equippable::setWisBoost(int wbst)
{
	if (wbst < 0 || wbst > 5)
		std::cout << "Can only buff with values between 0 and 5, inclusively." << std::endl;
	else
		wisboost = wbst;
}
Equippable::Equippable(ItemType itype, int lvladj)
{
	std::cout << "Generating level-adjusted equippable item..." << std::endl;
	std::cout << std::endl;
	setIType(itype);
	setItemID(equipIDCTR++);
	std::cout << "Equip ID: " << getItemID() << std::endl;
	
	//LEVEL ADJUSTMENT MODIFIER DETERMINATION
	int leveladjustmod;
	if (lvladj >= 0 && lvladj <= 5)
		leveladjustmod = 0;
	else if (lvladj > 5 && lvladj <= 10)
		leveladjustmod = 1;
	else if (lvladj > 15 && lvladj <= 20)
		leveladjustmod = 2;
	else if (lvladj > 20)
		leveladjustmod = 3;


	if (itype == HELMET)
	{
		setName("Helmet");
		//INTELLIGENCE
		if (roll(2) == 1)
			setIntBoost(0);
		else
		{
			setIntBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getIntBoost()) + " Intelligence, ");
		}


		//WISDOM
		if (roll(2) == 1)
			setWisBoost(0);
		else
		{
			setWisBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getWisBoost()) + " Wisdom, ");
		}
		//ARMOR CLASS
		if (roll(2) == 1)
			setArmBoost(0);
		else
		{
			setArmBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getArmBoost()) + " Armor. ");
		}
	}
	else if (itype == ARMOR)
	{
		setName("Armor");
		//ARMOR CLASS
		if (roll(2) == 1)
			setArmBoost(0);
		else
		{
			setArmBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getArmBoost()) + " Armor ");
		}

		//INHERENT ARMOR MODIFIER/TYPE ROLLS
		
		int typeroller = std::rand() % 6 + leveladjustmod;
		setArmType((ArmorType)typeroller);
		setName(getName() + " of type: " + std::to_string(getArmType()) + ".");
	}

	else if (itype == BRACERS)
	{
		setName("Bracers");
		//ARMOR CLASS
		if (roll(2) == 1)
			setArmBoost(0);
		else
		{
			setArmBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getArmBoost()) + " Armor, ");
		}

		//STRENGTH
		if (roll(2) == 1)
			setStrBoost(0);
		else
		{
			setStrBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getStrBoost()) + " Strength.");
		}
	}

	else if (itype == SHIELD)
	{
		setName("Sheild");
		//SHIELD
		if (roll(2) == 1)
			setArmBoost(0);
		else
		{
			setArmBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getArmBoost()) + " Armor ");
		}

		//INHERENT SHIELD MODIFIER/TYPE ROLLS

		int typeroller = std::rand() % 3;
		setShType((ShieldType)typeroller);
		setName(getName() + " of type: " + std::to_string(getArmType()) + ".");
	}

	else if (itype == RING)
	{
		setName("Ring");
		//ARMOR CLASS
		if (roll(2) == 1)
			setArmBoost(0);
		else
		{
			setArmBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getArmBoost()) + " Armor, ");
		}

		//STRENGTH
		if (roll(2) == 1)
			setStrBoost(0);
		else
		{
			setStrBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getStrBoost()) + " Strength, ");
		}

		//CONSTITUTION
		if (roll(2) == 1)
			setConBoost(0);
		else
		{
			setConBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getConBoost()) + " Constitution, ");
		}

		//WISDOM
		if (roll(2) == 1)
			setWisBoost(0);
		else
		{
			setWisBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getWisBoost()) + " Wisdom, ");
		}

		//CHARISMA
		if (roll(2) == 1)
			setChaBoost(0);
		else
		{
			setChaBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getChaBoost()) + " Charisma.");
		}
	}

	else if (itype == BELT)
	{
		setName("Belt");
		//CONSTITUTION
		if (roll(2) == 1)
			setConBoost(0);
		else
		{
			setConBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getConBoost()) + " Constitution, ");
		}

		//STRENGTH
		if (roll(2) == 1)
			setStrBoost(0);
		else
		{
			setStrBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getStrBoost()) + " Strength.");
		}
	}

	else if (itype == BOOTS)
	{
		setName("Boots");
		//ARMOR CLASS
		if (roll(2) == 1)
			setArmBoost(0);
		else
		{
			setArmBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getArmBoost()) + " Armor, ");
		}

		//DEXTERITY
		if (roll(2) == 1)
			setDexBoost(0);
		else
		{
			setDexBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getDexBoost()) + " Dexterity.");
		}
	}

	else if (itype == SWORD)
	{
		setName("Sword");
		//ATTACK
		if (roll(2) == 1)
			setAtkBoost(0);
		else
		{
			setAtkBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getAtkBoost()) + " Attack, ");
		}

		//DAMAGE
		if (roll(2) == 1)
			setDmgBoost(0);
		else
		{
			setDmgBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getDmgBoost()) + " Damage.");
		}
	}

	else if (itype == BOW)
	{
		setName("Bow");
		//ATTACK
		if (roll(2) == 1)
			setAtkBoost(0);
		else
		{
			setAtkBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getAtkBoost()) + " Attack, ");

		}

		//DAMAGE
		if (roll(2) == 1)
			setDmgBoost(0);
		else
		{
			setDmgBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getDmgBoost()) + " Damage.");
		}
	}
}
Equippable::Equippable(std::string nm, ItemType itype)
{
	std::cout << "Generating equippable item..." << std::endl;
	std::cout << std::endl;
	setName(nm);
	setIType(itype);
	setItemID(equipIDCTR++);
	std::cout << nm << std::endl;
	std::cout << "Equip ID: " << getItemID() << std::endl;

	
	if (itype == HELMET)
	{
		//INTELLIGENCE
		if (roll(2) == 1)
			setIntBoost(0);
		else 
			setIntBoost(roll(2));

		//WISDOM
		if (roll(2) == 1)
			setWisBoost(0);
		else 
			setWisBoost(roll(2));

		//ARMOR CLASS
		if (roll(2) == 1)
			setArmBoost(0);
		else 
			setArmBoost(roll(2));
	}

	else if (itype == ARMOR)
	{
		//ARMOR CLASS
		if (roll(2) == 1)
			setArmBoost(0);
		else 
			setArmBoost(roll(2));

		int typeroller = roll(9) - 1;
		setArmType((ArmorType)typeroller);
	}

	else if (itype == BRACERS)
	{
		//ARMOR CLASS
		if (roll(2) == 1)
			setArmBoost(0);
		else
			setArmBoost(roll(2));

		//STRENGTH
		if (roll(2) == 1)
			setStrBoost(0);
		else
			setStrBoost(roll(2));
	}

	else if (itype == SHIELD)
	{
		//SHIELD
		if (roll(2) == 1)
			setArmBoost(0);
		else 
			setArmBoost(roll(5));

		int typeroller = roll(3) - 1;
		setShType((ShieldType)typeroller);
	}

	else if (itype == RING)
	{
		//ARMOR CLASS
		if (roll(2) == 1)
			setArmBoost(0);
		else 
			setArmBoost(roll(5));

		//STRENGTH
		if (roll(2) == 1)
			setStrBoost(0);
		else 
			setStrBoost(roll(5));

		//CONSTITUTION
		if (roll(2) == 1)
			setConBoost(0);
		else 
			setConBoost(roll(5));

		//WISDOM
		if (roll(2) == 1)
			setWisBoost(0);
		else 
			setWisBoost(roll(5));

		//CHARISMA
		if (roll(2) == 1)
			setChaBoost(0);
		else 
			setChaBoost(roll(5));
	}

	else if (itype == BELT)
	{
		//CONSTITUTION
		if (roll(2) == 1)
			setConBoost(0);
		else 
			setConBoost(roll(5));

		//STRENGTH
		if (roll(2) == 1)
			setStrBoost(0);
		else 
			setStrBoost(roll(5));
	}

	else if (itype == BOOTS)
	{
		//ARMOR CLASS
		if (roll(2) == 1)
			setArmBoost(0);
		else 
			setArmBoost(roll(5));

		//DEXTERITY
		if (roll(2) == 1)
			setDexBoost(0);
		else 
			setDexBoost(roll(5));
	}

	else if (itype == SWORD)
	{
		//ATTACK
		if (roll(2) == 1)
			setAtkBoost(0);
		else 
			setAtkBoost(roll(5));

		//DAMAGE
		if (roll(2) == 1)
			setDmgBoost(0);
		else 
			setDmgBoost(roll(5));
	}

	else if (itype == BOW)
	{
		//ATTACK
		if (roll(2) == 1)
			setAtkBoost(0);
		else
			setAtkBoost(roll(5));

		//DAMAGE
		if (roll(2) == 1)
			setDmgBoost(0);
		else
			setDmgBoost(roll(5));
	}
};

bool Equippable::saveEquippable(std::string filename)
{
	std::ofstream f(filename, std::ios::out);

	if (f.is_open())
	{
		f	<< Equippable::getName() << std::endl
			<< Equippable::getEqStatus() << std::endl
			<< type << std::endl
			<< armtype << std::endl
			<< armormod << std::endl
			<< shtype << std::endl
			<< shieldmod << std::endl
			<< armboost << std::endl
			<< wisboost << std::endl
			<< conboost << std::endl
			<< chaboost << std::endl
			<< strboost<< std::endl
			<< intboost << std::endl
			<< dexboost << std::endl
			<< atkboost << std::endl
			<< dmgboost << std::endl
			<< Equippable::getItemID() << std::endl;
		f.close();
		std::cout << "SAVE COMPLETE" << std::endl;
		system("PAUSE");
		return true;
	}
	else
	{
		return false;
	}
}

bool Equippable::loadEquippable(std::string filename)
{
	//TEMP CRAP
	std::string tempname;
	bool tempeq;
//	ItemType temptype;
//	ArmorType temparmtype;
	int temparmmod;
//	ShieldType tempshtype;
	int tempshmod;
	int temparmboost;
	int tempwisboost;
	int tempconboost;
	int tempchaboost;
	int tempstrboost;
	int tempintboost;
	int tempdexboost;
	int tempatkboost;
	int tempdmgboost;
	int tempitemid;

	std::ifstream f(filename, std::ios::in);
	
	if (f.is_open())
	{
		f >> tempname;
		Equippable::setName(tempname);
		f >> tempeq;
		Equippable::setEqStatus(tempeq);
	//	f >> ITEMTYPE!?;
	//	f >> ARMORTYPE!?;
		f >> armormod;
	//	f >> SHIELDTYPE!?;
		f >> shieldmod;
		f >> armboost;
		f >> wisboost;
		f >> conboost;
		f >> chaboost;
		f >> strboost;
		f >> intboost;
		f >> dexboost;
		f >> atkboost;
		f >> dmgboost;
		f >> tempitemid;
		Equippable::setItemID(tempitemid);


		
		
		return true;
	}
}


//------------CONTAINER CLASS-------------------//

Container::Container()
{
	std::cout << "Generating a generic Container... " << std::endl;


	std::vector<Equippable> containervector;
}

Container::Container(std::string nm, Container::ContainerType typ)
{
	std::cout << "Generating a Container... " << nm << std::endl;
	setName(nm);
	Container::setCType(typ);

	std::vector<Equippable> containervector;
}

void Container::addEQtoContainer(Equippable eqp)
{
	std::cout << "Inserting " << eqp.getName() << " to container." << std::endl;
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
			std::cout << "Removing " << containervector[i].getName() << " from container." << std::endl;
			containervector.erase(containervector.begin() + i);
			remCTR++;
		}
		if (remCTR != 0)
			break;
	}

	notify();
}

Equippable Container::getEQfromContainer(int id)
{
	int getCTR = 0;

	for (int i = 0; i < containervector.size(); i++)
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

std::string Container::output()
{
	std::ostringstream streamer;

	if (containervector.size() != 0)
	{
		//std::cout << "CONTAINER VECTOR SIZE IS NOT 0" << std::endl;
		for (int i = 0; i < containervector.size(); i++)
		{
			streamer << ": " << containervector[i].getName() << std::endl;
			//std::cout << "ITERATING THROUGH VECTOR TO OUTPUT ITEMS" << std::endl;
		}
		return streamer.str();
	}

	else
		return Container::getName() + " is empty.\n";
}

void Container::setCType(Container::ContainerType ct)
{
	chtype = ct;
}

Container::ContainerType Container::getCType()
{
	return chtype;
}