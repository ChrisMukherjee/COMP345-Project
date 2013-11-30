// Subject Header File
// By: Christopher Mukherjee

#pragma once
#include <list>
using namespace std;

class Observer;

class Subject {
public:
	virtual ~Subject() {};
	virtual void attach(Observer* o );
	virtual void detach(Observer*  o);
	virtual void notify();

protected:
	Subject() {};

private:
	list<Observer*> observers;
};

