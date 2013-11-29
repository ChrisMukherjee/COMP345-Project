#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "Dice.h"
#include "Observable.h"
#include "GridContent.h"
#include <fstream>

class Item : public GridContent
{
public:
	std::string getName();
	void setName(std::string nm);
	int getItemID();
	void setItemID(int id);
	

private:
	std::string name;
	int itemID;
};

class Equippable: public Item
{
public:

	

    static enum ItemType
	{
		SWORD, BOW, SHIELD, HELMET, ARMOR, BRACERS, BELT, BOOTS, RING
	};
    static enum ArmorType
	{
		NADEF, PADDED, LEATHER, STUDDEDLEATHER, CHAINSHIRT, BREASTPLATE, BANDEDMAIL, HALFPLATE, FULLPLATE
	};
    static enum ShieldType
	{
		NSDEF, BUCKLER, HEAVYSHIELD, TOWERSHIELD
	};

	ItemType getIType();
	void setIType(ItemType ityp);
	ArmorType getArmType();
	void setArmType(ArmorType armtyp);
	ShieldType getShType();
	void setShType(ShieldType shtyp);

	bool getEqStatus();
	void setEqStatus(bool eq);

	//--------------------------------------\\
	
	int getArmMod();
	void setArmMod(int armmd);

	int getShMod();
	void setShMod(int shmd);


	//--------------------------------------\\

	int getArmBoost();
	void setArmBoost(int arbst);
	
	int getAtkBoost();
	void setAtkBoost(int atbst);

	int getChaBoost();
	void setChaBoost(int chbst);

	int getConBoost();
	void setConBoost(int cobst);
	
	int getDexBoost();
	void setDexBoost(int debst);

	int getDmgBoost();
	void setDmgBoost(int dmbst);

	int getIntBoost();
	void setIntBoost(int ibst);

	int getStrBoost();
	void setStrBoost(int sbst);

	int getWisBoost();
	void setWisBoost(int wbst);

	static std::string getAllEnchantments(Equippable eqp);
	
	Equippable(std::string nm, ItemType itype);
	Equippable(ItemType itype, int lvladj);

	std::string saveEquippable();
    static Equippable* loadEquippable(std::string strname);


private:
	bool equipped;
	ItemType type;
	ArmorType armtype;
	ShieldType shtype;
	int armormod;
	int shieldmod;
	int armboost;
	int wisboost;
	int conboost;
	int chaboost;
	int strboost;
	int intboost;
	int dexboost;
	int atkboost;
	int dmgboost;
	static int equipIDCTR;
	//static int consumIDCTR;
	//ENCHANTMENT RANDOMIZATION


	/*
	Depending on the type passed, roll dice to randomly generate a number associated with each enchantment seperately. BEFORE THIS, roll a die to see if
	you will even GET a value for a particular enchantment. For example: If a helment takes WIS and CHA, roll a die to see if you get a WIS boost. If yes, then
	roll another die to see what amount of it you get. Then do the same with CHA.
	*/
};

class Container : public Item, public Observable
{
public:
	std::vector<Equippable> containervector;

	//TYPE RELATED FUNCTIONS
	enum ContainerType
	{
		RANDOMIZED, ADJUSTED
	};

	void setCType(ContainerType ct);
	ContainerType getCType();

	void addEQtoContainer(Equippable eqp);
	void remEQfromContainer(int id);
	Equippable* getEQfromContainer(int id);

	Container();
	Container(std::string nm, ContainerType typ);

	//OUTPUTTERS
	std::string output();

private:
	
	ContainerType chtype;

};
