#pragma once
#include "ContainerObserver.h"
#include <iostream>

using namespace std;

ContainerObserver::ContainerObserver(Backpack& c)
{
	subject = &c;
	subject->attach(this);

	cout << "Successfully attached." << endl;
};

ContainerObserver::~ContainerObserver()
{
	subject->detach(this);
	subject = NULL;

	cout << "Successfully detached." << endl;
}

void ContainerObserver::update(Subject* modsubject)
{
	if (modsubject == subject)
		displayInventory();

	cout << "Container Observer UPDATE function was called." << endl;
}

void ContainerObserver::displayInventory()
{
	cout << subject->output();

	cout << "Container Observer DISPLAYINVENTORY function was called" << endl;
}