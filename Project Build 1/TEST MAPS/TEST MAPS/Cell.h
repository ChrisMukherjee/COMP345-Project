#pragma once

#include "GridContent.h"
#include "Item.h"
class Cell
{
public:
	static enum state
	{
		WALL,
		START,
		EXIT,
		EMPTY,
		OCCUPIED,
		MONSTER,
		CHEST
	};
	
	Cell(GridContent* gc = nullptr, state = EMPTY);
	virtual ~Cell(void);

	void setState(state);
	void setImage();

	state currentState;
	GridContent* gc;
	Item* it;
	char image;



};

