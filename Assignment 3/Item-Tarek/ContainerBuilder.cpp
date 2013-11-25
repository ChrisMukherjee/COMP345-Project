#pragma once
#include "ContainerBuilder.h"
#include "Dice.h"
#include <sstream>
using namespace std;
string ContainerBuilder::nameGenerator()
{
	ostringstream streamer;

	streamer << "Generic Item # " << roll(100) << endl;
	return streamer.str();
}

Container* ContainerBuilder::getContainer()
{
	return m_container;
}

void ContainerBuilder::createNewContainer()
{
	m_container = new Container;
}

