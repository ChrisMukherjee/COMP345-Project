#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
//----------------------------\\
  /* GENERAL ITEM FUNCTIONS */
//-----------------------------\\

/* ACCESSORS */

bool Item::getEqStatus()
{
	return equipped;
}

Item::ItemType Item::getIType()
{
	return type;
}

string Item::getName()
{
	return name;
}

/* MUTATORS */

void Item::setEqStatus(bool eqs)
{
	equipped = eqs;
}

void Item::setIType(ItemType itp)
{
	type = itp;
}

void Item::setName(string nm)
{
	name = nm;
}

//------------------------------\\
  /* HELMET SPECIFIC FUNCTIONS*/
//------------------------------\\

/* Constructor */

Helmet::Helmet(string nm, int abst, int wbst, int ibst)
{
	setIType(HELMET);
	setName(nm);
	setEqStatus(false);
	setArmBoost(abst);
	setWisBoost(wbst);
	setIntBoost(ibst);
	
}

/* Accessors */

int Helmet::getArmBoost()
{
	return armboost;
}

int Helmet::getWisBoost()
{
	return wisboost;
}

int Helmet::getIntBoost()
{
	return intboost;
}

/* Mutators */

void Helmet::setArmBoost(int aboost)
{
	if (aboost < 0 || aboost > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;	
	else	
		armboost = aboost;
}

void Helmet::setWisBoost(int wboost)
{
	if (wboost < 0 || wboost > 5)
		cout << "Can only buff with values between 0 and 5, invlusively." << endl;
	else
		wisboost = wboost;
}

void Helmet::setIntBoost(int iboost)
{
	if (iboost < 0 || iboost > 5)
		cout << "Can only buff with values between 0 and 5, invlusively." << endl;
	else
		intboost = iboost;
}

//------------------------------\\
  /* Armor Specific Functions */
//------------------------------\\

/* Constructor */

Armor::Armor(string nm, int abst)
{
	setIType(ARMOR);
	setName(nm);
	setEqStatus(false);
	setArmBoost(abst);
}

/* Accessors */

int Armor::getArmBoost()
{
	return armboost;
}

/* Mutators */

void Armor::setArmBoost(int aboost)
{
	if (aboost < 0 || aboost > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		armboost = aboost;
}

//-------------------------------\\
  /* SHIELD SPECIFIC FUNCTIONS */
//-------------------------------\\

/* Constructor */

Shield::Shield(string nm, int abst)
{
	setIType(SHIELD);
	setName(nm);
	setEqStatus(false);
	setArmBoost(abst);
}

/* Accessors */

int Shield::getArmBoost()
{
	return armboost;
}

/* Mutators */

void Shield::setArmBoost(int aboost)
{
	if (aboost < 0 || aboost > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		armboost = aboost;
}

//----------------------------\\
  /* RING SPECIFIC FUNCTIONS*/
//----------------------------\\

/* Constructor */

Ring::Ring(string nm, int abst, int wbst, int sbst, int chbst, int cobst)
{
	setIType(RING);
	setName(nm);
	setEqStatus(false);
	setArmBoost(abst);
	setWisBoost(wbst);
	setStrBoost(sbst);
	setChaBoost(chbst);
	setConBoost(cobst);
}

/* Accessors */

int Ring::getArmBoost()
{
	return armboost;
}

int Ring::getWisBoost()
{
	return wisboost;
}

int Ring::getStrBoost()
{
	return strboost;
}

int Ring::getChaBoost()
{
	return chaboost;
}

int Ring::getConBoost()
{
	return conboost;
}

/* Mutators */

void Ring::setArmBoost(int aboost)
{
	if (aboost < 0 || aboost > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		armboost = aboost;
}

void Ring::setWisBoost(int wboost)
{
	if (wboost < 0 || wboost > 5)
		cout << "Can only buff with values between 0 and 5, invlusively." << endl;
	else
		wisboost = wboost;
}

void Ring::setStrBoost(int sboost)
{
	if (sboost < 0 || sboost > 5)
		cout << "Can only buff with values between 0 and 5, invlusively." << endl;
	else
		strboost = sboost;
}

void Ring::setChaBoost(int chboost)
{
	if (chboost < 0 || chboost < 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		chaboost = chboost;
}

void Ring::setConBoost(int coboost)
{
	if (coboost < 0 || coboost > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		conboost = coboost;
}
//----------------------------\\
  /* Belt Related Functions */
//----------------------------\\

/* Constructor */

Belt::Belt(string nm, int cobst, int sbst)
{
	setIType(BELT);
	setName(nm);
	setEqStatus(false);
	setStrBoost(sbst);
	setConBoost(cobst);

}

/* Accessors */

int Belt::getStrBoost()
{
	return strboost;
}

int Belt::getConBoost()
{
	return conboost;
}


/* Mutators */

void Belt::setStrBoost(int sboost)
{
	if (sboost < 0 || sboost > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		strboost = sboost;
}

void Belt::setStrBoost(int sboost)
{
	if (sboost < 0 || sboost > 5)
		cout << "Can only buff with values between 0 and 5, invlusively." << endl;
	else
		strboost = sboost;
}

//---------------------------------------------------------------------\\
  /* BOOT RELATED FUNCTIONS (boot like the footwear, not bootup...lol*/
//---------------------------------------------------------------------\\

/* Constructor */

Boots::Boots(string nm, int dbst, int abst)
{
	setIType(BOOTS);
	setName(nm);
	setEqStatus(false);
	setDexBoost(dbst);
	setArmBoost(abst);

}

/* Accessors */

int Boots::getDexBoost()
{
	return dexboost;
}

int Boots::getArmBoost()
{
	return armboost;
}


/* Mutators */

void Boots::setDexBoost(int dboost)
{
	if (dboost < 0 || dboost > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		dboost = dboost;
}

void Boots::setArmBoost(int aboost)
{
	if (aboost < 0 || aboost > 5)
		cout << "Can only buff with values between 0 and 5, invlusively." << endl;
	else
		armboost = aboost;
}

//------------------------------\\
  /* WEAPON RELATED FUNCTIONS */
//------------------------------\\

/* Constructor */

Weapon::Weapon(string nm, int dmbst, int atbst)
{
	setIType(WEAPON);
	setName(nm);
	setEqStatus(false);
	setAtkBoost(atbst);
	setDmgBoost(dmbst);

}

/* Accessors */

int Weapon::getAtkBoost()
{
	return atkboost;
}

int Weapon::getDmgBoost()
{
	return dmgboost;
}


/* Mutators */

void Weapon::setDmgBoost(int dmboost)
{
	if (dmboost < 0 || dmboost > 5)
		cout << "Can only buff with values between 0 and 5, inclusively." << endl;
	else
		dmgboost = dmboost;
}

void Weapon::setAtkBoost(int atboost)
{
	if (atboost < 0 || atboost > 5)
		cout << "Can only buff with values between 0 and 5, invlusively." << endl;
	else
		atkboost = atboost;
}

//------------CONTAINER CLASS STUFF-------------------//

/* DUE TO UNFORESEEN DESIGN CONSEQUENCES, THIS SECTION IS STILL UNDER DEVELOPMENT (SEE README)*/

// WHAT THE HECK? IS A HELMET/ARMOR/etc.. NOT AN ITEM?! IT'S A CHILD CLASS! Have to rethink the design ...AGAIN.
void Backpack::addToBackpack(Item itm)
{
	if (itm.getIType = 0)
		addHelm(itm);

	else if (itm.getIType = 1)
		addArmor(itm);

	else if (itm.getIType = 2)
		addShield(itm);

	else if (itm.getIType = 3)
		addBelt(itm);

	else if (itm.getIType = 4)
		addBoots(itm);

	else if (itm.getIType = 5)
		addRing(itm);

	else if (itm.getIType = 6)
		addWeapon(itm);

};

string Backpack::getName()
{
	return name;
}

void Backpack::setName(string nm)
{
	name = nm;
}