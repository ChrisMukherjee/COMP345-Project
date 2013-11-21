// Map Driver File
// By: Christopher Mukherjee

#include <iostream>
#include <vector>
#include "Map.h"
#include "MapObserver.h"
#include "InputManager.h"
#include "windows.h"
#include "Build.h"
using namespace std;

int main() {
	int userHeight = 0;
	int userWidth = 0;
	char choice;
	bool end = false;

	do {
		cout << endl << "Would you like to create a (n)ew map," << endl << "or build an (A)rena map to get right into the game?" << endl << "n = new" << endl << "a = arena map" << endl << "Enter a character: ";
		cin >> choice;
	}
	while (choice != 'n' && choice != 'a');

	if (choice == 'n') {
		cout << endl << "Please enter a width for your map: ";
		cin >> userWidth;
		cout << endl << "Please enter a height for your map: ";
		cin >> userHeight;
		cout << endl << endl;

		Map testMap = Map(userWidth, userHeight);

		while (1) {
			// Output map so user can see his/her changes
			cout << testMap.output();
			// Reset variable to false
			bool checkValid = false;
			bool completed = false;

			while (!checkValid) {
				char editChar = ' ';
				int editWidth = 0;
				int editHeight = 0;

				cout << endl << "Options:" << endl << " # : Wall" << endl << " S : Start" << endl << " E : End" << endl << " C : Chest" << endl << " M : Monster" << endl << " = : Empty Space" << endl;
				cout << endl << "You can also enter Q to quit and discard your map, or V to validate and save your map." << endl;
				cout << endl << "Enter an acceptable character: ";
				cin >> editChar;

				// If user enters Q, quit program
				if (editChar == 'Q')
					return 0;

				// If user enters V, exit loop and run validation code
				if (editChar == 'V') {
					completed = true;
					break;
				}

				do {
					cout << endl << "Enter the horizontal index of the cell you wish to edit: ";
					cin >> editWidth;
					// Make sure the index is valid
					if (editWidth > (testMap.getWidth()-1) || editWidth < 0)
						cout << "Invalid width! Please try again." << endl;
				}
				while (editWidth > (testMap.getWidth()-1) || editWidth < 0);

				do {
					cout << endl << "Enter the vertical index of the cell you wish to edit: ";
					cin >> editHeight;
					// Make sure the index is valid
					if (editHeight > (testMap.getHeight()-1) || editHeight < 0)
						cout << "Invalid height! Please try again." << endl;
				}
				while (editHeight > (testMap.getHeight()-1) || editHeight < 0);

				cout << endl << endl;

				// Run set method for each type of cell
				if (editChar == '#') {
					checkValid = testMap.setWall(editWidth, editHeight);
				}
				else if (editChar == 'S') {
					checkValid = testMap.setStart(editWidth, editHeight);
				}
				else if (editChar == 'E') {
					checkValid = testMap.setEnd(editWidth, editHeight);
				}
				else if (editChar == 'C') {
					checkValid = testMap.setChest(editWidth, editHeight);
				}
				else if (editChar == 'M') {
					checkValid = testMap.setMonster(editWidth, editHeight);
				}
				else if (editChar == '=') {
					checkValid = testMap.setEmpty(editWidth, editHeight);
				}
				else {
					// Print out helpful error message
					cout << endl << "Invalid character! Please enter an acceptable character." << endl;
				}
			}
		
			// Run validation method and output message
			if (completed) {
				if (testMap.validate()) {
					testMap.playGame();
					MapObserver obs(&testMap);
					cin.get();

					system("CLS");
					cout << endl << "Map successfully created! Use the arrow keys or w, a, s, d to move your character." << endl << endl;
					// Output map
					cout << testMap.output();

					vector<InputEvent> events;
					// Map w, a, s, d keypresses to Input Events
					events.push_back(InputEvent("w", VK_UP));
					events.push_back(InputEvent("s", VK_DOWN));
					events.push_back(InputEvent("a", VK_LEFT));
					events.push_back(InputEvent("d", VK_RIGHT));
					// This one should always be last
					events.push_back(InputEvent("q", VK_ESCAPE));

					string dir;
					while (end == false || dir != "q") {
						dir = InputManager::getInput(events);
						system("CLS");
						end = testMap.move(dir.at(0));
					}

					break;
				}
				else
					cout << endl << "Sorry, this map is invalid. Please review it and fix any errors." << endl << endl << endl;
			}
		}
	}
	else if (choice == 'a') {
		// Create the Director
		Build build;
		// Create the Concrete Builder
		MapBuilder* arenaBuilder = new ArenaBuilder;

		// Tell the Director which Builder to use
		build.setMapBuilder(arenaBuilder);
		// Tell the Director to construct the Product
		build.constructMap(7, 7);
		Map* testMap = build.getMap();

		cin.get();
		testMap->playGame();
		MapObserver obs(testMap);

		system("CLS");

		vector<InputEvent> events;
		// Map w, a, s, d keypresses to Input Events
		events.push_back(InputEvent("w", 0x57));
		events.push_back(InputEvent("s", 0x53));
		events.push_back(InputEvent("a", 0x41));
		events.push_back(InputEvent("d", 0x44));
		// Map arrow keypresses to Input Events
		events.push_back(InputEvent("w", VK_UP));
		events.push_back(InputEvent("s", VK_DOWN));
		events.push_back(InputEvent("a", VK_LEFT));
		events.push_back(InputEvent("d", VK_RIGHT));
		// This one should always be last
		events.push_back(InputEvent("q", VK_ESCAPE));

		string dir;
		while (end == false && dir != "q") {
			dir = InputManager::getInput(events);
			system("CLS");
			cout << endl << "Use the arrow keys or w, a, s, d to move your character." << endl << endl;
			end = testMap->move(dir.at(0));
		}
	}

	if (end == true)
		cout << endl << "You have reached the End! Thank you for playing. Press enter to exit..." << endl;
	else
		cout << endl << "Thank you for playing. Press enter to exit..." << endl;

	cin.get();
	cin.get();
	return 0;
}