#include "Item.h"


Item::Item(std::string name, Item::ItemSlot slot)
{
	Item::name = name;
	Item::slot = slot;
}

Item::~Item()
{
}
