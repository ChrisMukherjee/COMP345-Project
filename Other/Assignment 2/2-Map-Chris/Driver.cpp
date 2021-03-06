// Map Driver File
// By: Christopher Mukherjee

#include <iostream>
#include <vector>
#include "map.h"
#include "MapObserver.h"
#include "InputManager.h"
#include "windows.h"
using namespace std;

int main() {
	int userHeight = 0;
	int userWidth = 0;
	char choice;
	bool end = false;

	do {
		cout << endl << "Would you like to create a (n)ew map," << endl << "or use an auto-generated (t)est map to get right into the game?" << endl << "n = new" << endl << "t = test map" << endl << "Enter a character: ";
		cin >> choice;
	}
	while (choice != 'n' && choice != 't');

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

				cout << endl << "Options:" << endl << " | : Vertical Wall" << endl << " - : Horizontal Wall" << endl << " S : Start" << endl << " E : End" << endl << " C : Chest" << endl << " M : Monster" << endl << " = : Empty Space" << endl;
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

				// Run setCell method
				checkValid = testMap.setCell(editWidth, editHeight, editChar);
			}
		
			// Run validation method and output message
			if (completed) {
				if (testMap.validate()) {
					testMap.playGame();
					MapObserver obs(&testMap);

					cout << endl << "Map successfully created! Use the arrow keys or w, a, s, d to move your character." << endl << endl;
					// Output map
					cout << testMap.output();

					vector<InputEvent> events;
					// Map w, a, s, d keypresses to Input Events
					events.push_back(InputEvent("w", VK_UP));
					events.push_back(InputEvent("s", VK_DOWN));
					events.push_back(InputEvent("a", VK_LEFT));
					events.push_back(InputEvent("d", VK_RIGHT));
					//This one should always be last
					events.push_back(InputEvent("q", VK_ESCAPE));

					string dir;
					while (end == false || dir != "q") {
						dir = InputManager::getInput(events);
						end = testMap.move(dir.at(0));
					}

					break;
				}
				else
					cout << endl << "Sorry, this map is invalid. Please review it and fix any errors." << endl << endl << endl;
			}
		}
	}
	else if (choice == 't') {
		Map testMap = Map();
		// Output map
		cout << testMap.output();
		testMap.playGame();
		MapObserver obs(&testMap);

		cout << endl << "Use the arrow keys or w, a, s, d to move your character." << endl << endl;
		// Output map
		cout << testMap.output();

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
		//This one should always be last
		events.push_back(InputEvent("q", VK_ESCAPE));

		string dir;
		while (end == false && dir != "q") {
			dir = InputManager::getInput(events);
			end = testMap.move(dir.at(0));
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