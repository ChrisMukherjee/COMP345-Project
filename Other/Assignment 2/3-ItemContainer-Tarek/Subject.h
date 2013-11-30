#pragma once
#include <list>
#include "Observer.h"
using namespace std;

class Observer;

class Subject
{

private:
	list<Observer*> observers;

public:
	virtual ~Subject();
	virtual void attach(Observer *obs);
	virtual void detach(Observer *obs);
	virtual void notify();

	Subject();

};