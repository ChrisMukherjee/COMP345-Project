// Generic Map Builder Header File
// By: Christopher Mukherjee

#pragma once
#include "Map.h"

class MapBuilder
{
public:
	// Get the built Map from the Builder
	Map* getMap() { return builtMap; }
	// Build a generic 5x5 empty Map
	void createNewMap(int w, int h) { builtMap = new Map(w, h); }
	// Create each part of the Map according to subtypes
	virtual void buildWall() = 0;
	virtual void buildStart() = 0;
	virtual void buildEnd() = 0;
	virtual void buildChest() = 0;
	virtual void buildMonster() = 0;
protected:
	// Map built by Builder
	Map* builtMap;
};
