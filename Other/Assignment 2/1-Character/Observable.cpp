#include "Observable.h"

Observable::Observable()
{
}

Observable::~Observable()
{
}

void Observable::attach(Observer* o)
{
	views.push_back(o);
}

void Observable::detach(Observer* o)
{
	views.remove(o);
}

void Observable::notify()
{
	std::list<Observer*>::iterator i;
	for (i = views.begin(); i != views.end(); ++i)
	{
		(*i)->update(this);
	}

}
