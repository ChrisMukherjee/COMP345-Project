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

	
	cout << endl;

	Container playerInventory("Player Inventory");

	Container chest1("Chest");
	
	cout << endl;

	ContainerObserver piObserver(playerInventory);

	ContainerObserver ch1Observer(chest1);

	cout << endl;

	system("pause");
	
	cout << endl;


	Equippable axe("Dagger of Stabbing", Equippable::WEAPON);

	cout << endl;

	cout << "ATK BOOST: " << axe.getAtkBoost() << endl;
	cout << "DMG BOOST: " << axe.getDmgBoost() << endl;
	
	cout << endl;

	system("pause");
	
	cout << endl;

	playerInventory.addEQtoContainer(axe);
	
	cout << endl;

	system("pause");

	cout << endl;
	cout << endl;



	Equippable sword("Maul of Smashing", Equippable::WEAPON);

	cout << endl;

	cout << "ATK BOOST: " << sword.getAtkBoost() << endl;
	cout << "DMG BOOST: " << sword.getDmgBoost() << endl;

	cout << endl;

	system("pause");

	cout << endl;

	chest1.addEQtoContainer(sword);
	
	cout << endl;

	system("pause");

	chest1.remEQfromContainer(1001);
	
	cout << endl;

	system("pause");

	playerInventory.remEQfromContainer(1000);

	cout << endl;

	system("pause");
	

	return (0);

}