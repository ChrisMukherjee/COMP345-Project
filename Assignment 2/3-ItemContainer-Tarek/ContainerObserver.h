#pragma once

#include "Observer.h"
#include "Item.h"

class ContainerObserver : public Observer
{
private:
	Backpack *subject;

public:
	ContainerObserver(Backpack& c);
	virtual ~ContainerObserver();
	virtual void update(Subject* modsubject);
	void displayInventory();
};