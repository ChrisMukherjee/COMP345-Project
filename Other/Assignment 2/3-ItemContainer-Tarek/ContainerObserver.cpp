#pragma once
#include "ContainerObserver.h"
#include <iostream>

using namespace std;

ContainerObserver::ContainerObserver(Container &c)
{
	subject = &c;
	subject->attach(this);

	cout << "Successfully attached observer to " << c.getName() << endl;
};

ContainerObserver::~ContainerObserver()
{
	subject->detach(this);
	subject = NULL;

	cout << "Successfully detached observer." << endl;
}

void ContainerObserver::update(Subject* modsubject)
{
	if (modsubject == subject)
		displayInventory();

	//cout << "Container Observer UPDATE function was called." << endl;
}

void ContainerObserver::displayInventory()
{
	cout << subject->output();

	//cout << "Container Observer DISPLAYINVENTORY function was called" << endl;
}