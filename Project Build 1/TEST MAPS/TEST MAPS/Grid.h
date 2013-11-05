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
	

	void setWalls();
	void setOccu(GridContent* gc);
	void setStart();
	void setEnd();
	void startGame(Character* c);
	void move(std::string direction);
	
	std:: string output();
	


private:
	int height;
	int width;
	Cell** grid;
	int startX, startY, endX,endY;
	int playerX,playerY;

	bool equals(Grid otherMap);

};
