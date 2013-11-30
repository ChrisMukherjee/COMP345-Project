// Map Observer Implementation File
// By: Christopher Mukherjee

#include <iostream>
#include "MapObserver.h"
#include "Subject.h"
#include "Map.h"
using namespace std;

MapObserver::MapObserver(Map* s)
{
	subject = s;
	subject->attach(this);
}

MapObserver::~MapObserver()
{
	subject->detach(this);
}

void MapObserver::update(Subject* changed)
{
	if (changed == subject)
		draw();
}

void MapObserver:: draw()
{
	cout << subject->output();
}