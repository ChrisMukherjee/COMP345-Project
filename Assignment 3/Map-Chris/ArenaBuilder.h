// Arena Builder Header File
// By: Christopher Mukherjee

#pragma once
#include "MapBuilder.h"

//Concrete Builder
class ArenaBuilder : public MapBuilder {
public:
	//Build different parts of the Arena map
	virtual void buildWall();
	virtual void buildStart();
	virtual void buildEnd();
	virtual void buildChest();
	virtual void buildMonster();
};
