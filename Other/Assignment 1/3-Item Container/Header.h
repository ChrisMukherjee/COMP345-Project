#include <string>
#include <iostream>
#include <vector>
using namespace std;

//============================//
//========ITEM CLASSES========//
//============================//

class Item
{
public:
	enum ItemType
	{
		HELMET, ARMOR, SHIELD, BELT, BOOTS, RING, WEAPON
	};
	string getName();
	void setName(string nm);
	ItemType getIType();
	void setIType(ItemType ityp);
	bool getEqStatus();
	void setEqStatus(bool eq);

private:
	string name;
	bool equipped;
	ItemType type;




};
/*class Bonus
{
	enum EnchantmentType{ARM, DMG, ATK, STR, INT, WIS, CHA, CON, DEX};
};

//NOT SURE YET...
*/
//-----------------------------HELMET-------------------------------//
class Helmet : public Item
{
private:
	int armboost;
	int wisboost;
	int intboost;

public:
	int getArmBoost();
	void setArmBoost(int aboost);
	int getWisBoost();
	void setWisBoost(int wboost);
	int getIntBoost();
	void setIntBoost(int iboost);

	Helmet(string nm, int abst, int wbst, int ibst);

};
 
//-------------------------------ARMOR----------------------------//
class Armor : public Item
{
private:
	int armboost;

public:
	int getArmBoost();
	void setArmBoost(int aboost);

	Armor(string nm, int abst);
};

//------------------------------SHIELD----------------------------//
class Shield : public Item
{
private:
	int armboost;

public:
	int getArmBoost();
	void setArmBoost(int aboost);

	Shield(string nm, int abst);
};


//-------------------------------RING----------------------------//
class Ring : public Item
{
private:
	int armboost;
	int wisboost;
	int conboost;
	int chaboost;
	int strboost;

public:
	int getArmBoost();
	void setArmBoost(int aboost);
	int getWisBoost();
	void setWisBoost(int wboost);
	int getStrBoost();
	void setStrBoost(int sboost);
	int getChaBoost();
	void setChaBoost(int chboost);
	int getConBoost();
	void setConBoost(int coboost);

	Ring(string nm, int abst, int wbst, int sbst, int chbst, int cobst);

};

//------------------------------BELT---------------------------------//

class Belt : public Item
{
private:
	int conboost;
	int strboost;

public:
	int getConBoost();
	void setConBoost(int coboost);
	int getStrBoost();
	void setStrBoost(int sboost);

	Belt(string nm, int sbst, int cobst);
};

//----------------------------BOOTS-----------------------------------//

class Boots : public Item
{
private:
	int dexboost;
	int armboost;

public:
	int getDexBoost();
	void setDexBoost(int dboost);
	int getArmBoost();
	void setArmBoost(int aboost);

	Boots(string nm, int dbst, int abst);
};

//---------------------------WEAPONS----------------------------------//

class Weapon : public Item
{
private:
	int atkboost;
	int dmgboost;

public:
	int getAtkBoost();
	void setAtkBoost(int atboost);
	int getDmgBoost();
	void setDmgBoost(int dmboost);

	Weapon(string nm, int atbst, int dmbst);
};

//=======================//
//===CONTAINER CLASSES===//
//=======================//

/* THIS SECTION IS STILL UNDER DEVELOPMENT (SEE README)*/

class Container
{
	//Need to think of relation between backpack and items in the dungeons..? (Thinking for the future of the project)
};

class Backpack : public Container
{
public:

	string getName();
	void setName(string nm);
	
	void addHelm(Helmet hlm);
	void addArmor(Armor arm);
	void addShield(Shield shl);
	void addRing(Ring rng);
	void addBelt(Belt blt);
	void addBoots(Boots bts);
	void addWeapon(Weapon wpn);

	// WHAT THE HECK? IS A HELMET/ARMOR/etc.. NOT AN ITEM?! IT'S A CHILD CLASS! 
	void addToBackpack(Item itm);


	Backpack(string nm)
	{
		setName(nm);

		
		vector<Helmet> HelmetPouch;
		vector<Armor> ArmorPouch;
		vector<Shield> ShieldPouch;
		vector<Ring> RingPouch;
		vector<Belt> BeltPouch;
		vector<Boots> BootPouch;
		vector<Weapon> WeaponPouch;
		

		//vector<Item *> directInventory;    This probably won't work well..

	}
	

private:
	string name;

};

