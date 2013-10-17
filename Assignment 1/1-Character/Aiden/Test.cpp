#include <iostream>
#include <ctime>
#include "Dice.h"
#include "Fighter.h"

using namespace std;

// This file is just being used to test this
int main()
{
	// Set seed to current time
	//srand(static_cast<unsigned int>(time(NULL)));
	srand(NULL);

	// Make a new Fighter
	Character* f1 = new Fighter("Regdar");

	// Equip some items for the Fighter
	f1->equip( *(new Item("Steel Helmet", Item::ItemSlot::HELMET)) );
	f1->equip( *(new Item("Chainmail", Item::ItemSlot::ARMOUR)) );
	f1->equip( *(new Item("Ring of Dexterity +1", Item::ItemSlot::RING)) );
	f1->equip( *(new Item("Book of Reading", Item::ItemSlot::MISC)) ); //Should not work
	
	f1->unequip( Item::ItemSlot::HELMET );

	// Print the Character sheet
	f1->characterSheet();

	delete f1;

	// Some input so the window doesn't close right away
	int a;
	cin >> a;
	return 0;
}