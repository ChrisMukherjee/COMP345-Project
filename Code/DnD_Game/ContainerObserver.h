#pragma once

#include "Observer.h"
#include "Item.h"

class ContainerObserver : public Observer
{
private:
	Container *subject;

public:
	ContainerObserver(Container &c);
	virtual ~ContainerObserver();
	virtual void update(Observable* modsubject);
	void displayInventory();
};