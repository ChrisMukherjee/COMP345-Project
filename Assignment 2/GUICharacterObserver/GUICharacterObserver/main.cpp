#include "gcharacterobserver.h"
#include <QApplication>
#include "Fighter.h"
#include "Item.h"
#include <ctime>

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(NULL)));

    QApplication a(argc, argv);
    GCharacterObserver w;
    Fighter* f = new Fighter("Buddy", 1);
    w.setSubject(*f);
    w.show();

    f->equip( *(new Item("Chainmail", Item::ItemSlot::ARMOUR)) );
    f->equip( *(new Item("Iron Sword", Item::ItemSlot::WEAPON)) );
    f->equip( *(new Item("Wooden Shield", Item::ItemSlot::SHIELD)) );
    f->equip( *(new Item("Lucky Ring", Item::ItemSlot::RING)) );
    f->equip( *(new Item("Leather Boots", Item::ItemSlot::BOOTS)) );

    return a.exec();
}
