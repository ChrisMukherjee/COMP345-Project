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

	virtual void ContainerBuilder::fillCVector()
	{
		/* static cast fix by aiden -- working and compiles
		for (int i = 1; i <= roll(3); i++)
		{
			m_container->addEQtoContainer(Equippable(ContainerBuilder::nameGenerator(), static_cast<Equippable::ItemType>(roll(8, 1, -1)) , leveladjustmodficiation));
		}
		*/

		int itemTypeRoller = roll(9) - 1;
		switch (itemTypeRoller)
		{
		case 0:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::SWORD, leveladjustmodficiation));
			}
			break;
		case 1:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::BOW, leveladjustmodficiation));
			}
			break;
		case 2:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::SHIELD, leveladjustmodficiation));
			}
			break;
		case 3:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::HELMET, leveladjustmodficiation));
			}
			break;
		case 4:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::ARMOR, leveladjustmodficiation));
			}
			break;
		case 5:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::BRACERS, leveladjustmodficiation));
			}
			break;
		case 6:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::BELT, leveladjustmodficiation));
			}
			break;
		case 7:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::BOOTS, leveladjustmodficiation));
			}
			break;
		case 8:
			for (int i = 1; i <= roll(3); i++)
			{
				m_container->addEQtoContainer(Equippable(nameGenerator(), Equippable::RING, leveladjustmodficiation));
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

	void constructContainer()
	{
		m_containerBuilder->createNewContainer();
		m_containerBuilder->buildCType();
		m_containerBuilder->fillCVector();

	}

private:
	ContainerBuilder* m_containerBuilder;
};

