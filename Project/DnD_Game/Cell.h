#pragma once

#include "GridContent.h"
class Cell
{
public:
	static enum state
	{
		WALL,
		START,
		EXIT,
		EMPTY,
		OCCUPIED
	};
	
	Cell(GridContent* gc = nullptr, state = EMPTY);
	virtual ~Cell(void);

	void setState(state);
	void setImage();

	state currentState;
	GridContent* gc;
	char image;



};

