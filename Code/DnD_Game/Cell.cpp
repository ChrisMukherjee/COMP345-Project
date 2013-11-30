#include "Cell.h"
#include "Character.h"

Cell::Cell() :
	currentState(EMPTY),
	content(NULL)
{
    image = '.';
}

Cell::Cell(state s, GridContent* c) :
	currentState(s),
	content(c)
{
	setImage();
}

Character* Cell::getCharacter()
{
	if (isCharacter())
	{
		return dynamic_cast<Character*>(content);
	}
	else
	{
		return NULL;
	}
}

Monster* Cell::getMonster()
{
	if (isMonster())
	{
		return dynamic_cast<Monster*>(content);
	}
	else
	{
		return NULL;
	}
}


Container* Cell::getContainer()
{
    if (isContainer())
    {
        return dynamic_cast<Container*>(content);
    }
    else
    {
        return NULL;
    }
}

void Cell::setState(Cell::state s, GridContent* c)
{
	currentState = s;
	content = c;
	setImage();
}

void Cell::setImage()
{
	switch (currentState)
	{
	case START:
		image = 'S';
		break;
	case EXIT:
		image = 'E';
		break;
	case EMPTY:
		image = ' ';
		break;
	case WALL:
		image = '#';
		break;
	case CHARACTER:
		image = getCharacter()->image;
		break;
	case MONSTER:
		image = getMonster()->image;
		break;
    case MONSTERDEAD:
        image = 'm';
        break;
    case CONTAINER:
        image = getContainer()->image;
       // image = 'C';
        break;
    case CONTAINEREMPTY:
        image = 'c';
        break;
    }
}
