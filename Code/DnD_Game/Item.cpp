#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Item.h"
#include <sstream>

#include <QDebug>
#include <QString>

int Equippable::equipIDCTR = 1000;

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
			setArmBoost(getArmBoost() + 0);
		else if (artyp == PADDED)
			setArmBoost(getArmBoost() + 1);
		else if (artyp == LEATHER)
			setArmBoost(getArmBoost() + 2);
		else if (artyp == STUDDEDLEATHER)
			setArmBoost(getArmBoost() + 3);
		else if (artyp == CHAINSHIRT)
			setArmBoost(getArmBoost() + 4);
		else if (artyp == BREASTPLATE)
			setArmBoost(getArmBoost() + 5);
		else if (artyp == BANDEDMAIL)
			setArmBoost(getArmBoost() + 6);
		else if (artyp == HALFPLATE)
			setArmBoost(getArmBoost() + 7);
		else if (artyp == FULLPLATE)
			setArmBoost(getArmBoost() + 8);
	}
}

void Equippable::setShType(ShieldType shtyp)
{
	if (type = SHIELD)
	{
		shtype = shtyp;
		if (shtyp == NSDEF)
			setArmBoost(getArmBoost() + 0);
		else if (shtyp == BUCKLER)
			setArmBoost(getArmBoost() + 1);
		else if (shtyp == HEAVYSHIELD)
			setArmBoost(getArmBoost() + 2);
		else if (shtyp == TOWERSHIELD)
			setArmBoost(getArmBoost() + 4);
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
	setIType(itype);
	setItemID(equipIDCTR++);
	equipped = false;
	ItemType type;
	armtype = NADEF;
	shtype = NSDEF;
	armboost = 0;
	wisboost = 0;
	conboost = 0;
	chaboost = 0;
	strboost = 0;
	intboost = 0;
	dexboost = 0;
	atkboost = 0;
	dmgboost = 0;

	int leveladjustmod = 0;
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

		int typeroller = std::rand() % 6 + leveladjustmod;
		setArmType((ArmorType)typeroller);
		//setName(getName() + " with an armor modifier of " + std::to_string(getArmMod()) + ".");
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
		setName("Shield");
		//SHIELD
		if (roll(2) == 1)
			setArmBoost(0);
		else
		{
			setArmBoost(roll(2) + leveladjustmod);
			setName(getName() + ": +" + std::to_string(getArmBoost()) + " Armor ");
		}

		int typeroller = std::rand() % 3;
		setShType((ShieldType)typeroller);
		//setName(getName() + " with a shield modifier of " + std::to_string(getShMod()) + ".");
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

std::string Equippable::saveEquippable()
{
	std::ostringstream ostreamer;
	
		ostreamer	<< Equippable::getName() << "$"
				<< Equippable::getEqStatus() << "$"
                << Equippable::type << "$"
                << Equippable::armtype << "$"
			/*	<< armormod << "$"	*/
                << Equippable::shtype << "$"
			/*	<< shieldmod << "$"	*/
				<< armboost << "$"
				<< wisboost << "$"
				<< conboost << "$"
				<< chaboost << "$"
				<< strboost << "$"
				<< intboost << "$"
				<< dexboost << "$"
				<< atkboost << "$"
				<< dmgboost << "$"
                << Equippable::getItemID();

		return ostreamer.str();

}

Equippable* Equippable::loadEquippable(std::string strname)
{
	std::string delimiter = "$";
	size_t pos = 0;
	std::string token;
	int count = 0;

    if (!strname.find(delimiter)) {
        return NULL;
    }
    Equippable* ptr = new Equippable(Equippable::SWORD, 0);

    while ((pos = strname.find(delimiter)) != std::string::npos)
	{
		
		switch (count)
		{
		case 0:
			{
				token = strname.substr(0, pos);
				ptr->setName(token);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			  }
		case 1:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
				ptr->setEqStatus(value);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			  }
		case 2:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
                ItemType t;
                switch (value) {
                case 0:
                    t = SWORD;
                    break;
                case 1:
                    t = BOW;
                    break;
                case 2:
                    t = SHIELD;
                    break;
                case 3:
                    t = HELMET;
                    break;
                case 4:
                    t = ARMOR;
                    break;
                case 5:
                    t = BRACERS;
                    break;
                case 6:
                    t = BELT;
                    break;
                case 7:
                    t = BOOTS;
                    break;
                case 8:
                    t = RING;
                    break;
                }
                ptr->setIType(t);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			  }
		case 3:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
//                ArmorType t;
//                switch (value) {
//                case 0:
//                    t = NADEF;
//                    break;
//                case 1:
//                    t = PADDED;
//                    break;
//                case 2:
//                    t = LEATHER;
//                    break;
//                case 3:
//                    t = STUDDEDLEATHER;
//                    break;
//                case 4:
//                    t = ARMOR;
//                    break;
//                case 5:
//                    t = BRACERS;
//                    break;
//                case 6:
//                    t = BELT;
//                    break;
//                case 7:
//                    t = BOOTS;
//                    break;
//                case 8:
//                    t = RING;
//                    break;
//                }
                ptr->setArmType(static_cast<ArmorType>(value));
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			  }
		case 4:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
                ptr->setShType(static_cast<ShieldType>(value));
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			  }
		case 5:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
				ptr->setArmBoost(value);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			  }
		case 6:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
				ptr->setWisBoost(value);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			  }
		case 7:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
				ptr->setConBoost(value);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			  }
		case 8:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
				ptr->setChaBoost(value);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			  }
		case 9:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
				ptr->setStrBoost(value);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			  }
		case 10:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
				ptr->setIntBoost(value);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			   }
		case 11:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
				ptr->setDexBoost(value);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			   }
		case 12:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
				ptr->setAtkBoost(value);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			   }
		case 13:
			{
				token = strname.substr(0, pos);
				std::istringstream buffer(token);
				int value;
				buffer >> value;
				ptr->setDmgBoost(value);
                strname.erase(0, pos + delimiter.length());
				count++;
				break;
			   }
		}
	}

	
	std::istringstream buffer(strname);
	int value;
	buffer >> value;
	ptr->setItemID(value);

	return ptr;
}

Container::Container()
{
	image = 'C';
}

Container::Container(std::string nm, Container::ContainerType typ)
{
	setName(nm);
	Container::setCType(typ);

	std::vector<Equippable> containervector;
}

void Container::addEQtoContainer(Equippable eqp)
{
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
			containervector.erase(containervector.begin() + i);
			remCTR++;
		}
		if (remCTR != 0)
			break;
	}

	notify();
}
Equippable* Container::getEQfromContainer(int id)
{
	return &containervector[id];
}

std::string Container::output()
{
	std::ostringstream streamer;

	if (containervector.size() != 0)
	{
		for (int i = 0; i < containervector.size(); i++)
		{
			streamer << ": " << containervector[i].getName() << std::endl;
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
