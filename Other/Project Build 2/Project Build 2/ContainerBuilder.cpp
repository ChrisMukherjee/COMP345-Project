#pragma once
#include "ContainerBuilder.h"
#include "Dice.h"
#include <sstream>

std::string ContainerBuilder::nameGenerator()
{
	std::ostringstream streamer;

	streamer << "Generic Item # " << roll(100) << std::endl;
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

