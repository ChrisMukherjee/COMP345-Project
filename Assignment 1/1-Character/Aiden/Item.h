#pragma once

#include <string>

// Placeholder class to hold items that a Character can hold/equip
class Item
{
public:
	static enum ItemSlot
	{
		WEAPON,
		SHIELD,
		HELMET,
		ARMOUR,
		BELT,
		BOOTS,
		RING,
		MISC
	};

	Item(std::string name = "DEFAULT ITEM", ItemSlot slot = Item::ItemSlot::MISC);
	~Item();

	std::string name;
	ItemSlot slot;
};
