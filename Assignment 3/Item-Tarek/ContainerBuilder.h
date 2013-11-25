#pragma once
#include "Item.h"
#include "Dice.h"
using namespace std;
class ContainerBuilder : public Container
{
public:
	//Support functions to help randomize items in container
	string nameGenerator();

	Container* getContainer();
	void createNewContainer();

	virtual void fillCVector() = 0;
	virtual void buildCType() = 0;


protected:
	Container* m_container;



};

class RandomContainerBuilder : public ContainerBuilder
{
public:
	virtual void ContainerBuilder::buildCType()
	{
		m_container->setCType(RANDOMIZED);
	}

	virtual void ContainerBuilder::fillCVector()
	{
		for (int i = 1; i <= roll(3); i++)
		{
			m_container->addEQtoContainer(Equippable::Equippable(nameGenerator(), Equippable::WEAPON));
		}
	}
};

class AdjustedContainerBuilder : public ContainerBuilder
{
public:
	virtual void ContainerBuilder::buildCType()
	{
		m_container->setCType(ADJUSTED);
	}

	virtual void ContainerBuilder::fillCVector()
	{
		for (int i = 1; i <= roll(3); i++)
		{
			m_container->addEQtoContainer(Equippable(nameGenerator(), static_cast<Equippable::ItemType>(roll(8, 1, -1)) , leveladjustmodficiation));
		}
	}
};

class Director
{
public:
	void setContainerBuilder(ContainerBuilder* cb)
	{
		m_containerBuilder = cb;
	}

	Container* getContainer()
	{
		return m_containerBuilder->getContainer();
	}

	void constructContainer()
	{
		m_containerBuilder->createNewContainer();
		m_containerBuilder->buildCType();
		m_containerBuilder->fillCVector();

	}

private:
	ContainerBuilder* m_containerBuilder;
};

