#pragma once

#include "Observable.h"
#include "Grid.h"
#include "Observer.h"


class GridObserver : public Observer
{
public:
	GridObserver(Grid* s);
	~GridObserver();

	 void update(Observable* theChangedSubject);
	 void draw();

private:
	Grid *subject;
};
