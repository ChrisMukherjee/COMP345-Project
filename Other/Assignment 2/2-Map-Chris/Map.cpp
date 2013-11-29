// Map Implementation File
// By: Christopher Mukherjee

#include <iostream>
#include <sstream>
#include "Map.h"
using namespace std;

// Default Constructor - creates a generic test map
Map::Map() {
	// Initialize variables
	width = 7;
	height = 7;
	onCell = '=';

	// Create 2D array
	mapArr = new char*[width];
	for (int i = 0; i < width; i++)
		mapArr[i] = new char[height];

	// Fill the array with empty spaces (=)
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			mapArr[j][i] = '=';
	}

	// Set up initial walls around
	for (int i = 0; i < width; i++) {
		mapArr[i][0] = '-';
		mapArr[i][height-1] = '-';
	}
	for (int i = 0; i < height; i++) {
		mapArr[0][i] = '|';
		mapArr[width-1][i] = '|';
	}
	// Set up corners
	mapArr[0][0] = '+';
	mapArr[width-1][0] = '+';
	mapArr[0][height-1] = '+';
	mapArr[width-1][height-1] = '+';

	// Add start and end
	mapArr[0][4] = 'S';
	mapArr[5][1] = 'E';
	mapArr[5][5] = 'C';
	mapArr[4][5] = '|';
	mapArr[4][4] = '|';
	mapArr[4][3] = '|';
	mapArr[1][1] = 'M';

	startX = 0;
	startY = 4;
	endX = 5;
	endY = 1;

};

// Parametrized Constructor
Map::Map(int w, int h) {
	// Initialize variables
	width = w+2;
	height = h+2;
	startX = -1;
	startY = -1;
	endX = -1;
	endY = -1;
	onCell = '=';

	// Create 2D array
	mapArr = new char*[width];
	for (int i = 0; i < width; i++)
		mapArr[i] = new char[height];

	// Fill the array with empty spaces (=)
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			mapArr[j][i] = '=';
	}

	// Set up initial walls around
	for (int i = 0; i < width; i++) {
		mapArr[i][0] = '-';
		mapArr[i][height-1] = '-';
	}
	for (int i = 0; i < height; i++) {
		mapArr[0][i] = '|';
		mapArr[width-1][i] = '|';
	}
	// Set up corners
	mapArr[0][0] = '+';
	mapArr[width-1][0] = '+';
	mapArr[0][height-1] = '+';
	mapArr[width-1][height-1] = '+';
};

// Destructor
Map::~Map() {
	// Delete the array
	delete mapArr;
};

// Set cells to user defined value
bool Map::setCell(int x, int y, char a) {
	// Cannot edit the corners of the map
	if (mapArr[x][y] == '+') {
		// Print out helpful error message
		cout << endl << "Sorry, you cannot edit the corners of the map (+)." << endl;
		return false;
	}
	// Start and End are added in a special way
	// Must make sure to only have one Start
	else if (a == 'S') {
		if (startX != -1 || startY != -1) {
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
		startX = x;
		startY = y;
		return true;
	}
	// Must make sure to only have one End
	else if (a == 'E') {
		if (endX != -1 || endY != -1) {
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
		endX = x;
		endY = y;
		return true;
	}
	// Can only add doors or walls to the edges
	else if ((x == 0 || x == width-1) || (y == 0 || y == height-1)) {
		if ((a == '-') && x != 0 && x != width-1) {
			// Reset Start and End locations, if replacing one
			if (mapArr[x][y] == 'S') {
				startX = -1;
				startY = -1;
			}
			if (mapArr[x][y] == 'E') {
				endX = -1;
				endY = -1;
			}
			mapArr[x][y] = a;
		}
		else if (a == '|' && y != 0 && y != height-1) {
			// Reset Start and End locations, if replacing one
			if (mapArr[x][y] == 'S') {
				startX = -1;
				startY = -1;
			}
			if (mapArr[x][y] == 'E') {
				endX = -1;
				endY = -1;
			}
			mapArr[x][y] = a;
		}
		else {
			// Print out helpful error message
			cout << endl << "Invalid character! You can only add a (S)tart cell, an (E)nd cell, or walls (-, |) to the edges of the map." << endl;
			return false;
		}
		return true;
	}
	// Any other acceptable character can be added in the map
	else if (a == '-' || a == '=' || a == '|' || a == 'C' || a == 'M') {
		// Reset Start and End locations, if replacing one
		if (mapArr[x][y] == 'S') {
			startX = -1;
			startY = -1;
		}
		// Reset Start and End locations, if replacing one
		if (mapArr[x][y] == 'E') {
			endX = -1;
			endY = -1;
		}
		mapArr[x][y] = a;
		return true;
	}
	else {
		// Print out helpful error message
		cout << endl << "Invalid character! Please enter an acceptable character." << endl;
		return false;
	}
	return true;
};

// Validate custom user-created map
bool Map::validate() {
	// First check to make sure the map has a Start and End
	if (startX == -1 || startY == -1 || endX == -1 || endY == -1) {
		cout << endl << "Your map must have one (S)tart cell and one (E)nd cell.";
		return false;
	}

	// Set up for map traversal
	// Create another array so that user's map remains unchanged
	char** visitedArr = new char*[width];
	for (int k = 0; k < width; k++)
		visitedArr[k] = new char[height];

	// Fill the new array with empty spaces (=)
	for (int k = 0; k < height; k++) {
		for (int l = 0; l < width; l++)
			visitedArr[l][k] = '=';
	}

	int i = startX;
	int j = startY;

	// Mark visited indices with a V character
	visitedArr[i][j] = 'V';

	while (i != endX || j != endY) {
		// Try going right
		if (i+1 < width && (mapArr[i+1][j] == '='|| mapArr[i+1][j] == 'E') && visitedArr[i+1][j] != 'V' && visitedArr[i+1][j] != 'Z') {
			i++;
			visitedArr[i][j] = 'V';
		}
		// Try going up
		else if (j-1 >= 0 && (mapArr[i][j-1] == '='|| mapArr[i][j-1] == 'E') && visitedArr[i][j-1] != 'V' && visitedArr[i][j-1] != 'Z') {
			j--;
			visitedArr[i][j] = 'V';
		}
		// Try going left
		else if (i-1 >= 0 && (mapArr[i-1][j] == '='|| mapArr[i-1][j] == 'E') && visitedArr[i-1][j] != 'V' && visitedArr[i-1][j] != 'Z') {
			i--;
			visitedArr[i][j] = 'V';
		}
		// Try going down
		else if (j+1 < height && (mapArr[i][j+1] == '='|| mapArr[i][j+1] == 'E') && visitedArr[i][j+1] != 'V' && visitedArr[i][j+1] != 'Z') {
			j++;
			visitedArr[i][j] = 'V';
		}
		// If none of the above movements are possible, we have reached a dead end
		else {
			// Mark dead end indices with a Z character
			visitedArr[i][j] = 'Z';

			// Change all the (V)isited indices back into empty (=) cells because they may need to be used for another traversal
			for (int k = 0; k < height; k++) {
				for (int l = 0; l < width; l++) {
					if (visitedArr[l][k] == 'V') {
						visitedArr[l][k] = '=';
					}
				}
			}

			// Reset i, j variables
			i = startX;
			j = startY;
		}

		// Invalid map (no way to get from Start to End)
		if (visitedArr[startX][startY] == 'Z')
			return false;
	}

	// If the loop exits, we have reached the end of the map
	return true;
};

// Output the map array as a grid
string Map::output() {
	// Create string stream to keep all data until output
	stringstream sstream;

	sstream << "    ";
	for (int i = 0; i < width; i++)
		sstream << i << "  ";
	sstream << endl << endl << endl;

	for (int i = 0; i < height; i++) {
		if (i > 9 && i < 100)
			sstream << i << "  ";
		else
			sstream << i << "   ";
		for (int j = 0; j < width; j++)
			sstream << mapArr[j][i] << "  ";
		sstream << endl << endl;
	}

	return sstream.str();
}

// Start the game (place the character on the map) once the map has been created
void Map::playGame()
{
	playerX = startX;
	playerY = startY;
	mapArr[playerX][playerY] = '&';
}

// Move the character in the game
bool Map::move(char direction)
{
	tmpX = playerX;
	tmpY = playerY;

	mapArr[playerX][playerY] = onCell;

	if (direction == 'd' || direction == 'D')
		tmpX = tmpX+1;
	else if (direction == 'w' || direction == 'W')
		tmpY = tmpY-1;
	else if (direction == 'a' || direction == 'A')
		tmpX = tmpX-1;
	else if (direction == 's' || direction == 'S')
		tmpY = tmpY+1;

	// Moveable location
	if (mapArr[tmpX][tmpY] == '=') {
		// Reset Start cell if moving from start
		if(playerX == startX && playerY == startY)
			mapArr[playerX][playerY] = 'S';
		playerX = tmpX;
		playerY = tmpY;
	}
	// Moved onto End cell
	else if (mapArr[tmpX][tmpY] == 'E') {
		playerX = tmpX;
		playerY = tmpY;
		onCell = mapArr[playerX][playerY];
		mapArr[playerX][playerY] = '&';
		notify();
		return true;
	}

	onCell = mapArr[playerX][playerY];
	mapArr[playerX][playerY] = '&';

	notify();
	return false;
}

// Accessor Functions
int Map::getWidth() {
	return width;
};
int Map::getHeight() {
	return height;
};