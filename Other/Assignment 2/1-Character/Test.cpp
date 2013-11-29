#include <iostream>
#include <ctime>
#include <conio.h>
#include "Fighter.h"
#include "CharacterObserver.h"

using namespace std;

// This file is just being used to test this
int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	Fighter f("Fighter1", 1);

	CharacterObserver o1(f);
	CharacterObserver o2(f);
	CharacterObserver o3(f);

	Item* i1 = new Item("Pants", Item::ItemSlot::ARMOUR);
	Item* i2 = new Item("Helmet", Item::ItemSlot::ARMOUR);

	cout << "Press any key to equip PANTS!" << endl;
	_getch();
	f.equip( *i1 );

	cout << "Press any key to equip HELMET!" << endl;
	_getch();
	f.equip( *i2 );

	return 0;
}