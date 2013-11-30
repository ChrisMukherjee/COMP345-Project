#pragma once

class Grid
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
	void output();
	


private:
	int height;
	int width;
	char** grid;
	int startX, startY, endX,endY;

	bool canMoveTo(char cell,int x, int y);
};
