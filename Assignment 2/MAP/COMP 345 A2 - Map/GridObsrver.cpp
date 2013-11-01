#include "GridObserver.h"
#include "Subject.h"
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

void GridObserver:: update(Subject* theChangedSubject)
{
	if (theChangedSubject == subject)
		draw();
}

void GridObserver:: draw()
{
	std:: cout<< subject->output();
}