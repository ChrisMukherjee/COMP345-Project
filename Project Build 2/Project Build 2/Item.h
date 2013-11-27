#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "Dice.h"
#include "Observable.h"
#include "GridContent.h"
#include <fstream>

//============================//
//========ITEM CLASSES========//
//============================//

class Item : public GridContent
{
public:
	std::string getName();
	void setName(std::string nm);
	int getItemID();
	void setItemID(int id);
	int leveladjustmodficiation;

private:
	std::string name;
	int itemID;
};

class Equippable: public Item
{
public:
	enum ItemType
	{
		SWORD, BOW, SHIELD, HELMET, ARMOR, BRACERS, BELT, BOOTS, RING
	};
	enum ArmorType
	{
		NADEF, PADDED, LEATHER, STUDDEDLEATHER, CHAINSHIRT, BREASTPLATE, BANDEDMAIL, HALFPLATE, FULLPLATE
	};
	enum ShieldType
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

	bool saveEquippable(std::string filename);
	bool loadEquippable(std::string filename);


private:
	bool equipped;
	ItemType type;
	ArmorType armtype = NADEF;
	ShieldType shtype = NSDEF;
	int armormod = 0;
	int shieldmod = 0;
	int armboost = 0;
	int wisboost = 0;
	int conboost = 0;
	int chaboost = 0;
	int strboost = 0;
	int intboost = 0;
	int dexboost = 0;
	int atkboost = 0;
	int dmgboost = 0;
	static int equipIDCTR;
	//static int consumIDCTR;
	//ENCHANTMENT RANDOMIZATION
	int enchantChance;
	int enchantAmount;

	/*
	Depending on the type passed, roll dice to randomly generate a number associated with each enchantment seperately. BEFORE THIS, roll a die to see if
	you will even GET a value for a particular enchantment. For example: If a helment takes WIS and CHA, roll a die to see if you get a WIS boost. If yes, then
	roll another die to see what amount of it you get. Then do the same with CHA.
	*/
};

class Container : public Item, public Observable
{
public:

	//TYPE RELATED FUNCTIONS
	enum ContainerType
	{
		RANDOMIZED, ADJUSTED
	};

	void setCType(ContainerType ct);
	ContainerType getCType();

	//ADD-REMOVE-GET EQ FROM CONTAINER
	//void addCONtoBP();
	//void remCONfromBP();
	void addEQtoContainer(Equippable eqp);
	void remEQfromContainer(int id);
	Equippable getEQfromContainer(int id);



	//Container Constructors
	Container();
	Container(std::string nm, ContainerType typ);

	//OUTPUTTERS
	std::string output();
	/*
	void open() const
	{
		cout << "Chest contains: " << endl;
		for (int i = 0; i <= containervector.size(); i++)
			cout << containervector[i].getName() << endl;
	}
	*/

private:
	std::vector<Equippable> containervector;
	ContainerType chtype;

};




/* Create new classes Chest, Chestbuilder, RandomChestBuilder and AdjustedChestbuilder. They all make new vector containers and new items depending on the type
of of chest it will be. You may have to modify the item creator method to take into account a randomized stat item or a level adjusted stat item..Maybe by taking in
an extra parameter which determines either random or adjusted item stats.

The chest class can have a variable for its type: random or adjusted. Make the mutator/accessor methods for this variable

It seems you need a manager for the chestbuilders... In the example it is the Director class*/