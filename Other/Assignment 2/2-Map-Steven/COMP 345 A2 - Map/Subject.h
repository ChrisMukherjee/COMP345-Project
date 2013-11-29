//Subject Class
#pragma once
#include <list>

class Observer;

class Subject{

public:
	virtual ~Subject() {};
	virtual void attach(Observer* o );
	virtual void detach(Observer*  o);
	virtual void notify();

protected:
	Subject() {};

private:
	std::list<Observer*> observers;


};

