// Arena Builder Implementation File
// By: Christopher Mukherjee

#include "ArenaBuilder.h"

void ArenaBuilder::buildWall() {
	// Walls do not need to be built since the constructor automatically generates walls around the map
};

void ArenaBuilder::buildStart() {
	builtMap->setStart(4, 8);
};

void ArenaBuilder::buildEnd() {
	builtMap->setEnd(4, 0);
};

void ArenaBuilder::buildChest() {
	builtMap->setChest(4, 4);
};

void ArenaBuilder::buildMonster() {
	builtMap->setMonster(4, 1);
};
