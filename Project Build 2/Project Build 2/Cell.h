#pragma once

#include "GridContent.h"
#include "Item.h"
#include "Monster.h"
#include "Container.h"
class Cell
{
public:
	static enum state
	{
		EMPTY,
		WALL,
		CHARACTER,
		MONSTER,
		CONTAINER
	};

public:
	Cell();
	Cell(state, GridContent* content = NULL);
	virtual ~Cell() {};

	bool isEmpty() {return currentState == EMPTY;}
	bool isWall() {return currentState == EMPTY;}
	bool isCharacter() {return currentState == CHARACTER;}
	bool isMonster() {return currentState == MONSTER;}
	bool isContainer() {return currentState == CONTAINER;}

	Monster* getMonster();
	Character* getCharacter();
	Container* getContainer();

	void setState(state s, GridContent* content);
	void setImage();

private:
	state currentState;
	GridContent* content;
	char image;
};

