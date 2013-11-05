#include "Cell.h"


Cell::Cell(GridContent* gc, Cell:: state theState)
{
	currentState = theState;
	setImage();
	this->gc = gc;

}

void Cell::setImage()
{
	switch (currentState)
	{
	case Cell::WALL:
		image = '#';
		gc = 0;
		break;
	case Cell::START:
		image = 'S';
		gc = 0;
		break;
	case Cell::EXIT:
		image = 'E';
		gc = 0;
		break;
	case Cell::EMPTY:
		image = ' ';
		gc = 0;
		break;
	case Cell::OCCUPIED:
		image = gc->image;
		break;
	}
}

void Cell::setState(state newState)
{
	currentState = newState;
	setImage();
}



Cell::~Cell(void)
{
}
