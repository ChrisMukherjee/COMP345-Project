// Map Observer Header File
// By: Christopher Mukherjee

#pragma once

#include "Subject.h"
#include "Map.h"
#include "Observer.h"


class MapObserver : public Observer {
public:
	MapObserver(Map* s);
	~MapObserver();
	void update(Subject* changed);
	void draw();

private:
	Map *subject;
};