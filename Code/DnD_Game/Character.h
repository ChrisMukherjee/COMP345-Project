#pragma once

#include <iostream>
#include <vector>

#include "Item.h"
#include "Dice.h"
#include "Observable.h"
#include "GridContent.h"
#include <string>

// A Character is a class for all characters in the game
class Character :
	public Observable,
	public GridContent
{

public:

	// Constructor and destructor
	Character(std::string name, int level);
	virtual ~Character();

	// Equips an item into a specified slot. If it's a ring, it will automatically equip in ring slot 1. If you want
	// to equip it in the other slot, you must specify ring slot 2
	void equip(Equippable& item);

	// Unequips an item and places it in your inventory
	void unequip(int slotToUnequip);

	void pickUp(Equippable* item);
	void drop(Equippable* item);

	// String representations of Character Sheet, equiped items, inv etc...
	std::string characterSheetToString();
	std::string attributesToString();
	std::string equipedToString();
	std::string invToString();
	std::string otherAttributesToString();
	std::string goldToString();

    void updateAttackBonus();

    // Save the Character to text file
	bool saveCharacter(std::string filename);

	// Load a Character from text file
	bool loadCharacter(std::string filename);

	// Attack a target
	void attack(Character* target);

	// Level a character!!
	virtual void levelUp() = 0;

	//A method to assign attributes that are class-specific
	virtual void assignOtherAttributes() = 0;

	virtual void recalculateAttributes() = 0;

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

    // Pixmap image of the Character
    int picture;

	// Hit points
	int maxHP,
		curHP;

	// Armour class - How hard it is for an attack to hit the character. Based on DEX and armour that is being worn
	int ac;

	// Attack bonus - The bonus that is applied to attacks against enemies. Based on STR and some skills or feats
	int meleeAttackBonus;

	std::vector<int> baseAttackBonus;
    std::vector<int> attackBonus;

	// Damage bonus - The bonus that is applied to all damage dealt by this character
	int meleeDmgBonus;

	// Personalizations - Name, age, weight, etc...
	std::string name;

	// Gold - How much money the character has
	int gold;

	int x, y;

	int initiative;

	int movesLeft;

    std::string attackinfo;

	// Equipped Items
	// 1: Weapon
	// 2: Shield
	// 3: Helmet
	// 4: Armour
	// 5: Bracers
	// 6. Belt
	// 7. Boots
	// 8. Ring
	std::vector<Equippable*> slot;

	// Inventory - for unequipped items that he picks up
	std::vector<Equippable*> inv;

    // Generate a random ability score between two bounds
    int generateAbilityScore();

protected:
	// Calculates the ability score modifier
	int calcModifier(int baseStat);

private:
	// Method to randomly generate the ability scores, assign them, and calculate the modifiers
	void assignAbilityScores();
}; // END Character
