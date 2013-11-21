// Builder Header File
// By: Christopher Mukherjee

#pragma once
#include "ArenaBuilder.h"

// Director
class Build
{
public:
	// Use a concrete builder
	void setMapBuilder(MapBuilder* mb) { mapBuilder = mb; }
	// Get the constructed Map
	Map* getMap() { return mapBuilder->getMap(); }
	// Create a Map using the specified builder
    void constructMap(int w, int h) {
		mapBuilder->createNewMap(w, h); 
		mapBuilder->buildWall();
		mapBuilder->buildStart();
		mapBuilder->buildEnd();
		mapBuilder->buildChest();
		mapBuilder->buildMonster(); }
private:
    MapBuilder* mapBuilder;
};