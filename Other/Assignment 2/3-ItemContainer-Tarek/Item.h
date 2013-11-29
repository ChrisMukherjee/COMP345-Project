#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "Dice.h"
#include "Subject.h"
using namespace std;

//============================//
//========ITEM CLASSES========//
//============================//

class Item
{
public:
	string getName();
	void setName(string nm);
	int getItemID();
	void setItemID(int id);

private:
	string name;
	int itemID;
};

class Equippable: public Item
{

public:
	enum ItemType
	{
		HELMET, ARMOR, SHIELD, BELT, BOOTS, RING, WEAPON
	};

	ItemType getIType();
	void setIType(ItemType ityp);

	bool getEqStatus();
	void setEqStatus(bool eq);

	

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

	static void getAllEnchantments(Equippable eqp);
	

	Equippable(string nm, ItemType typ);

private:
	bool equipped;
	ItemType type;
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
	int enchantChance;
	int enchantAmount;

	

	/*
	Depending on the type passed, roll dice to randomly generate a number associated with each enchantment seperately. BEFORE THIS, roll a die to see if
	you will even GET a value for a particular enchantment. For example: If a helment takes WIS and CHA, roll a die to see if you get a WIS boost. If yes, then
	roll another die to see what amount of it you get. Then do the same with CHA.
	*/
};



class Container : public Item, public Subject
{
public:


	void addEQtoContainer(Equippable eqp);
	//void addCONtoBP();

	void remEQfromContainer(int id);

	Equippable getEQfromContainer(int id);

	Container(string nm);

	string output();




private:
	vector<Equippable> containervector;

};




