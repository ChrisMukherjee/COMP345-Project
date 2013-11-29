// Map Header File
// By: Christopher Mukherjee

#pragma once
#include "Subject.h"
#include <String>
using namespace std;

class Map : public Subject {
public:
	// Default constructor creates a generic test map
	Map();
	Map(int w, int h);
	~Map();
	bool setCell(int x, int y, char a);
	bool move(char direction);
	string output();
	bool validate();
	void playGame();
	// Accessor Methods
	int getWidth();
	int getHeight();

private:
	// 2D array of characters
	char** mapArr;
	int height;
	int width;
	char onCell;
	int startX, startY, endX, endY, playerX, playerY, tmpX, tmpY;
};