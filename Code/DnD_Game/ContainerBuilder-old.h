#pragma once
#include "Item.h"
#include "Dice.h"

class ContainerBuilder : public Container
{
public:
	//Support functions to help randomize items in container
	std::string nameGenerator();

	Container* getContainer();
	void createNewContainer();

	virtual void fillCVector(int charlevel) = 0;
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

	virtual void ContainerBuilder::fillCVector(int charlevel)
	{
		int itemTypeRoller = roll(9) - 1;
		switch (itemTypeRoller)
		{
		case 0:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::SWORD));
			}
			break;
		case 1:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::BOW));
			}
			break;
		case 2:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::SHIELD));
			}
			break;
		case 3:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::HELMET));
			}
			break;
		case 4:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::ARMOR));
			}
			break;
		case 5:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::BRACERS));
			}
			break;
		case 6:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::BELT));
			}
			break;
		case 7:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::BOOTS));
			}
			break;
		case 8:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::RING));
			}
			break;
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

	virtual void ContainerBuilder::fillCVector(int charlevel)
	{
		/* static cast fix by aiden -- working and compiles
		for (int i = 1; i <= roll(3); i++)
		{
			m_container->addEQtoContainer(Equippable(ContainerBuilder::static_cast<Equippable::ItemType>(roll(8, 1, -1)) , charlevel));
		}
		*/

		int itemTypeRoller = roll(9) - 1;
		switch (itemTypeRoller)
		{
		case 0:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(Equippable::SWORD, charlevel));
			}
			break;
		case 1:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(Equippable::BOW, charlevel));
			}
			break;
		case 2:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(Equippable::SHIELD, charlevel));
			}
			break;
		case 3:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(Equippable::HELMET, charlevel));
			}
			break;
		case 4:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(Equippable::ARMOR, charlevel));
			}
			break;
		case 5:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(Equippable::BRACERS, charlevel));
			}
			break;
		case 6:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(Equippable::BELT, charlevel));
			}
			break;
		case 7:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(Equippable::BOOTS, charlevel));
			}
			break;
		case 8:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(Equippable::RING, charlevel));
			}
			break;
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

	void constructContainer(int charlevel)
	{
		m_containerBuilder->createNewContainer();
		m_containerBuilder->buildCType();
		m_containerBuilder->fillCVector(charlevel);

	}

private:
	ContainerBuilder* m_containerBuilder;
};

