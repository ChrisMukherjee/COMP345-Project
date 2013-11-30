#pragma once

#include <iostream>
#include <vector>

#include "Item.h"
#include "Dice.h"
#include "Observable.h"

// A Character is a class for all characters in the game
class Character : public Observable
{

public:

	//Constructor and destructor
	Character(std::string name = "Default Name", int level = 1);
	virtual ~Character();

	// Equips an item into a specified slot. If it's a ring, it will automatically equip in ring slot 1. If you want
	// to equip it in the other slot, you must specify ring slot 2
	void equip(Item& item, int ringSlot = 1);

	// Unequips an item and places it in your inventory
	void unequip(int slotToUnequip);

	// String representations of Character Sheet, equiped items, inv etc...
	std::string characterSheetToString();
	std::string attributesToString();
	std::string equipedToString();
	std::string invToString();
	std::string otherAttributesToString();
	std::string goldToString();


protected:
	//A method to assign atributes that are class-specific
	virtual void assignOtherAttributes() = 0;

	// Base ability score - The base ability score of the current player, based on level and original rolls
	int baseStr,
		baseDex,
		baseCon,
		baseInt,
		baseWis,
		baseCha;

	// Effective ability score - The current effective value of ability scores. This is the total of base plus any item mods that may apply to the given ability
	int effStr,
		effDex,
		effCon,
		effInt,
		effWis,
		effCha;

	// Ability modifiers - (effAttr - 10) / 2  rounded down
	int modStr,
		modDex,
		modCon,
		modInt,
		modWis,
		modCha;

	// Current Level of the Character
	int level;

	// Hitpoints
	int maxHP,
		curHP;

	// Armour class - How hard it is for an attack to hit the character. Based on DEX and armour that is being worn
	int ac;

	// Attack bonus - The bonus that is applied to attacks against enemies. Based on STR and some skills or feats
	int attackBonus;

	// Damage bonus - The bonus that is applied to all damage dealt by this character
	int dmgBonus;

	// Equiped Items
	// 1: Weapon
	// 2: Shield
	// 3: Helmet
	// 4: Armour
	// 5. Belt
	// 6. Boots
	// 7. Ring
	// 8. Misc
	std::vector<Item*> slot;

	// Inventory - for unequiped items that he picks up
	std::vector<Item*> inv;

	// Gold - How much money the character has
	int gold;

	// Personalisations - Name, age, weight, etc...
	std::string name;

private:
	// Calculates the ability score modifier
	int calcModifier(int baseStat);

	// Generate a random ability score between two bounds
	int generateAbilityScore();

	// Method to randomly generate the ability scores, assign them, and calculate the modifiers
	void assignAbilityScores();
}; // END Character
