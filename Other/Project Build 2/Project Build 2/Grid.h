#pragma once
#include "Observable.h"
#include "Cell.h"
#include "Character.h"
#include "Fighter.h"
#include "Monster.h"
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
	bool tryMove(Character* actor, std::string direction, bool isPlayer);

	void move(Character*, int , int);

	bool saveMap();
	static Grid* loadMap(int characterLevel);
	// Accessor Functions
	int getWidth() { return width; };
	int getHeight() { return height; };

	static bool inRange(int srcX, int srcY, int tarX, int tarY, int range);
	
	std:: string output();

	std::vector <Character*> actors;
	
	bool isStart(int x, int y) {return x == startX && y == startY;}
	bool isEnd(int x, int y) {return x == endX && y == endY;}

private:
	int height;
	int width;
	Cell** grid;
	int startX, startY, endX,endY;
	int playerX,playerY;

	int numMonsters;

	bool equals(Grid otherMap);
};
