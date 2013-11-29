#pragma once
#include <list>
#include <iterator>
#include "Subject.h"
using namespace std;

Subject::Subject() {}

Subject::~Subject() {}

void Subject::attach(Observer *obs)
{
	observers.push_back(obs);
}

void Subject::detach(Observer *obs)
{
	observers.remove(obs);
}

void Subject::notify()
{
	list<Observer*> ::iterator itr;
	for (itr = observers.begin(); itr != observers.end(); ++itr)
	{
		(*itr)->update(this);
	}
}