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

void ArenaBuilder::setLevel() {
	// Generate a random number between 1 and 10.
	// This number will be used to adjust the content of the chest and the difficulty level of the monster to the level of the character playing the map.
	// This level can only work with a proper chest container, and a character with levels (neither of which I have for the assignment).
	// This will come into play when combined with the other parts of the project.
	int l = rand() % 10 + 1;
	level = l;
};
