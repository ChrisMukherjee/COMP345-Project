#pragma once

#include "Subject.h"
#include "Grid.h"
#include "Observer.h"


class GridObserver : public Observer
{
public:
	GridObserver(Grid* s);
	~GridObserver();

	 void update(Subject* theChangedSubject);
	 void draw();

private:
	Grid *subject;
};