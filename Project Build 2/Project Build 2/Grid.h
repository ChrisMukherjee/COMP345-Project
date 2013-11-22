#pragma once
#include "Observable.h"
#include "Cell.h"
#include "Character.h"
#include <String>


class Grid : public Observable
{
public:
	Grid();
	Grid(int h, int w);
	~Grid();

	bool isValid();
	

	bool setCell(int w, int h, char x);
	void startGame(Character* c);
	bool move(std::string direction);

	bool saveMap();
	static Grid* loadMap();
	// Accessor Functions
	int getWidth() { return width; };
	int getHeight() { return height; };
	
	std:: string output();
	


private:
	int height;
	int width;
	Cell** grid;
	int startX, startY, endX,endY;
	int playerX,playerY;

	bool equals(Grid otherMap);

	//Helper methods to determine if a coord is a start or end tile
	bool isStart(int x, int y) {return x == startX && y == startY;}
	bool isEnd(int x, int y) {return x == endX && y == endY;}

};
