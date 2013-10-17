// Map Implementation File
// By: Christopher Mukherjee

#include <iostream>
#include "map.h"
using namespace std;

// Constructor
map::map(int w, int h) {
	width = w+2;
	height = h+2;
	hasS = false;
	hasE = false;

	mapArr = new char*[width];
	for (int i = 0; i < width; i++)
		mapArr[i] = new char[height];

	// Set up walls around
	for (int i = 0; i < width; i++) {
		mapArr[i][0] = '-';
		mapArr[i][height-1] = '-';
	}
	for (int i = 0; i < height; i++) {
		mapArr[0][i] = '|';
		mapArr[width-1][i] = '|';
	}
	mapArr[0][0] = '+';
	mapArr[width-1][0] = '+';
	mapArr[0][height-1] = '+';
	mapArr[width-1][height-1] = '+';
};

// Set cells to user defined value
bool map::setCell(int x, int y, char a) {
	// Cannot edit the corners of the map
	if (mapArr[x][y] == '+') {
		cout << endl << "Sorry, you cannot edit the corners of the map (+)." << endl;
		return false;
	}
	// Start and End are added in a special way
	// Must make sure to only have max one of each
	else if (a == 'S') {
		if (hasS) {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (mapArr[j][i] == 'S') {
						if (j == 0 || j == width-1)
							mapArr[j][i] = '|';
						else if (i == 0 || i == height-1)
							mapArr[j][i] = '-';
						else
							mapArr[j][i] = '=';
						break;
					}
				}
			}
		}
		mapArr[x][y] = 'S';
		hasS = true;
		return true;
	}
	else if (a == 'E') {
		if (hasE) {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (mapArr[j][i] == 'E') {
						if (j == 0 || j == width-1)
							mapArr[j][i] = '|';
						else if (i == 0 || i == height-1)
							mapArr[j][i] = '-';
						else
							mapArr[j][i] = '=';
						break;
					}
				}
			}
		}
		mapArr[x][y] = 'E';
		hasE = true;
		return true;
	}
	// Can only add doors or walls to the edges
	else if ((x == 0 || x == width-1) || (y == 0 || y == height-1)) {
		if ((a == '-') && x != 0 && x != width-1)
			mapArr[x][y] = a;
		else if (a == '|' && y != 0 && y != height-1)
			mapArr[x][y] = a;
		else {
			cout << endl << "Invalid character! You can only add a (S)tart cell, an (E)nd cell, or walls (-, |) to the edges of the map." << endl;
			return false;
		}
		return true;
	}
	// Any other acceptable character can be added in the grid
	else if (a == '-' || a == '|' || a == 'C' || a == 'M') {
		mapArr[x][y] = a;
		return true;
	}
	else {
		cout << endl << "Invalid character! Please enter an acceptable character." << endl;
		return false;
	}
	return true;
};

// Validate custom user-created map
bool map::validate() {

	return true;
};

// Output the map array as a grid
void map::output() {
	cout << "    ";
	for (int i = 0; i < width; i++)
		cout << i << "  ";
	cout << endl << endl << endl;

	for (int i = 0; i < height; i++) {
		if (i > 9 && i < 100)
			cout << i << "  ";
		else
			cout << i << "   ";
		for (int j = 0; j < width; j++)
			cout << mapArr[j][i] << "  ";
	cout << endl << endl;
	}
};

// Accessor Functions
int map::getWidth() {
	return width;
};
int map::getHeight() {
	return height;
};