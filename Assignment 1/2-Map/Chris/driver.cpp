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
		// Output map so user can see his/her changes
		testMap.output();
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
				cout << endl << "Map successfully created! Press enter to continue..." << endl << endl;
				break;
			}
			else
				cout << endl << "Sorry, this map is invalid. Please review it and fix any errors." << endl << endl << endl;
		}
	}

	cin.get();
	cin.get();
	return 0;
}