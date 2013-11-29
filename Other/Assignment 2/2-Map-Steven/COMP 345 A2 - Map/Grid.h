#pragma once
#include "Subject.h"
#include <String>


class Grid : public Subject
{
public:
	Grid();
	Grid(int h, int w);
	~Grid();

	bool isValid();
	

	void setWalls();
	void setOccu();
	void setStart();
	void setEnd();
	void startGame();
	void move(char direction);
	
	std:: string output();
	


private:
	int height;
	int width;
	char** grid;
	int startX, startY, endX,endY;
	int playerX,playerY;

	bool equals(Grid otherMap);

};
