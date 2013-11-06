#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Dice.h"
#include "ContainerObserver.h"
#include <sstream>
#include <ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	/*
	//DICE ROLL TESTING!
	cout << roll(2) << endl;
	cout << roll(2) << endl;
	cout << roll(2) << endl;
	cout << roll(2) << endl;
	cout << roll(2) << endl;
	cout << roll(2) << endl;
	cout << roll(2) << endl;
	cout << roll(2) << endl;
	system("pause");
	
	if (roll(2) == 1)
		cout << "0" << endl;
	else
		cout << roll(5) << endl;
	system("pause");
	if (roll(2) == 1)
		cout << "0" << endl;
	else
		cout << roll(5) << endl;
	system("pause");
	if (roll(2) == 1)
		cout << "0" << endl;
	else
		cout << roll(5) << endl;
	system("pause");
	if (roll(2) == 1)
		cout << "0" << endl;
	else
		cout << roll(5) << endl;
	system("pause");
	if (roll(2) == 1)
		cout << "0" << endl;
	else
		cout << roll(5) << endl;
	system("pause");
	*/
	
	Backpack pi("Player Inventory");

	ContainerObserver playerinventoryobserver(pi);

	system("pause");



	Equippable axe("Greataxe", Equippable::WEAPON);

	cout << "ATK BOOST: " << axe.getAtkBoost() << endl;
	cout << "DMG BOOST: " << axe.getDmgBoost() << endl;
	
	system("pause");

	pi.addEQtoBP(axe);
	
	system("pause");

	cout << endl;
	cout << endl;



	Equippable sword("Greatsword", Equippable::WEAPON);

	system("pause");

	cout << "ATK BOOST: " << sword.getAtkBoost() << endl;
	cout << "DMG BOOST: " << sword.getDmgBoost() << endl;

	system("pause");

	pi.addEQtoBP(sword);
	
	system("pause");

	pi.remEQfromBP(1001);
	
	system("pause");


	/*
	------------------------------------------------------------

	int dicetest = roll(5);
	cout << dicetest << endl;
	dicetest = roll(5);
	cout << dicetest << endl;
	dicetest = roll(6);
	cout << dicetest << endl;
	dicetest = roll(6);
	cout << dicetest << endl;
	system("pause");
	
	
	//Item creation

	cout << "Creating a weapon (Dagger of Stabbing) , shield, and armor with random attributes..." << endl;

	Equippable sword = Equippable("Dagger of Stabbing", Equippable::WEAPON);
	cout << endl;
	Equippable shield = Equippable("Shield of Defending", Equippable::SHIELD);
	cout << endl;
	Equippable armor = Equippable("Armor of Death Prevention", Equippable::ARMOR);
	cout << endl;
	
	cout << "Armor stat of shield: " << shield.getArmBoost() << endl;
	



	Equippable::getAllEnchantments(sword);
	cout << endl;
	Equippable::getAllEnchantments(shield);
	cout << endl;
	Equippable::getAllEnchantments(armor);
	cout << endl;

	

	cout << "Creating a Backpack...Items will be pushed in and out of it, demonstrating the use of the Observer patterns." << endl;

	Backpack PlayerInventory = Backpack("Abnormally Large Bag");

	cout << "Showing the current contents of player inventory..." << endl;

	PlayerInventory.output();

	cout << "Adding Dagger of Stabbing to the inventory and displaying" << endl;
	
	PlayerInventory.addEQtoBP(sword);

	PlayerInventory.output();

	cout << "Adding Shield of Defending to the inventory and displaying" << endl;

	PlayerInventory.addEQtoBP(shield);

	PlayerInventory.output();

	cout << "Adding Armor of Death Prevention to the inventory and displaying" << endl;

	PlayerInventory.addEQtoBP(armor);

	PlayerInventory.output();
	*/
	

	return (0);

}