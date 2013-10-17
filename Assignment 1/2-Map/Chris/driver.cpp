// Map Driver File
// By: Christopher Mukherjee

#include <iostream>
#include "map.h"
using namespace std;

int main() {
	int userHeight = 0;
	int userWidth = 0;

	cout << "Please enter a width for your map: ";
	cin >> userWidth;
	cout << endl << "Please enter a height for your map: ";
	cin >> userHeight;
	cout << endl << endl;

	map testMap = map(userWidth, userHeight);

	while (1) {
		testMap.output();
		bool checkValid = false;

		while (!checkValid) {
			int editWidth = 0;
			int editHeight = 0;
			char editChar = ' ';

			do {
				cout << endl << "Enter the horizontal index of the cell you wish to edit: ";
				cin >> editWidth;
				if (editWidth > (testMap.getWidth()-1))
					cout << "Invalid width! Please try again." << endl;
			}
			while (editWidth > (testMap.getWidth()-1));

			do {
				cout << endl << "Enter the vertical index of the cell you wish to edit: ";
				cin >> editHeight;
				if (editHeight > (testMap.getHeight()-1))
					cout << "Invalid height! Please try again." << endl;
			}
			while (editHeight > (testMap.getHeight()-1));

			cout << endl << "Options:" << endl << " | = Vertical Wall" << endl << " - = Horizontal Wall" << endl << " S = Start" << endl << " E = End" << endl << " C = Chest" << endl << " M = Monster" << endl;
			cout << endl << "You can also enter Q to quit and discard your map, or V to validate and save your map." << endl;
			cout << endl << "Enter the acceptable char you wish to place in this position: ";
			cin >> editChar;

			if (editChar == 'Q')
				return 0;

			if (editChar == 'V')
				break;

			checkValid = testMap.setCell(editWidth, editHeight, editChar);
		}
		
		if (testMap.validate()) {
			cout << "Map successfully created! Press enter to continue..." << endl;
			break;
		}
		else
			cout << "This map is invalid. Please review it and fix any errors." << endl;
	}

	cin.get();
	cin.get();
	return 0;
}