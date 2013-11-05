#include "GridObserver.h"
#include "Observable.h"
#include "Grid.h"
#include <iostream>

GridObserver:: GridObserver(Grid* s)
{
	subject = s;
	subject->attach(this);
}

GridObserver:: ~GridObserver()
{
	subject->detach(this);
}

void GridObserver:: update(Observable* theChangedSubject)
{
	if (theChangedSubject == subject)
		draw();
}

void GridObserver:: draw()
{
	std:: cout<< subject->output();
}