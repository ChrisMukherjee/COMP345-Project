#include "Character.h"
#include "CharacterObserver.h"
#include "Fighter.h"
#include <sstream>
#include <fstream>
#include "windows.h"

// Assign and initialize all the data members
Character::Character(std::string name, int level) :
    level(level),
    name(name)
{
    assignAbilityScores();
    updateAttackBonus();
}

Character::~Character()
{
    for (size_t i = 0; i < inv.size(); i++)
    {
        delete inv.at(i);
    }
}

void Character::updateAttackBonus()
{
    baseAttackBonus.clear();
    attackBonus.clear();
    if (level >= 16)
    {
        baseAttackBonus.push_back(level);
        baseAttackBonus.push_back(level - 5);
        baseAttackBonus.push_back(level - 10);
        baseAttackBonus.push_back(level - 15);
        attackBonus.push_back(level);
        attackBonus.push_back(level - 5);
        attackBonus.push_back(level - 10);
        attackBonus.push_back(level - 15);
    }
    else if (level >= 11)
    {
        baseAttackBonus.push_back(level);
        baseAttackBonus.push_back(level - 5);
        baseAttackBonus.push_back(level - 10);
        attackBonus.push_back(level);
        attackBonus.push_back(level - 5);
        attackBonus.push_back(level - 10);
    }
    else if (level >= 6)
    {
        baseAttackBonus.push_back(level);
        baseAttackBonus.push_back(level - 5);
        attackBonus.push_back(level);
        attackBonus.push_back(level - 5);
    }
    else
    {
        baseAttackBonus.push_back(level);
        attackBonus.push_back(level);
    }
}

// Ringslot is defaulted to 1
void Character::equip(Equippable& item)
{
    Equippable::ItemType t = item.getIType();
    if (t > 0)
    {
        t = static_cast<Equippable::ItemType>(t - 1);
    }
    if(slot[t] != NULL)
    {
        unequip( t );
    }
    slot[t] = &item;

    item.setName(item.getName());
    item.setEqStatus(true);
    static_cast<Fighter*>(this)->recalculateAttributes();
}

void Character::unequip(int slotToUnequip)
{
    if( !(slotToUnequip > 8 || slotToUnequip < 0) )
    {
        //If there is nothing in the slot, there's nothing to unequip!
        if(slot[slotToUnequip] != NULL)
        {
            slot[slotToUnequip]->setEqStatus(false);
            slot[slotToUnequip] = NULL;
        }
    }
    static_cast<Fighter*>(this)->recalculateAttributes();
}

void Character::pickUp(Equippable* item)
{
    inv.push_back(item);
}

void Character::drop(Equippable* item)
{
    for (size_t i = 0; i < inv.size(); ++i)
    {
        if (item == inv[i])
        {
            inv.erase(inv.begin() + i);
            inv.shrink_to_fit();
            delete item;
            break;
        }
    }
}


std::string Character::characterSheetToString()
{
    std::stringstream sstm;

    sstm << attributesToString() << std::endl
         << otherAttributesToString() << std::endl;

    return sstm.str();
}

std::string Character::attributesToString()
{
    std::stringstream sstm;

    sstm << "Name: " << name << ", level: " << level << std::endl << std::endl
         << "Strength: " << effStr << " || " << modStr << std::endl
         << "Dexterity: " << effDex << " || " << modDex << std::endl
         << "Constitution: " << effCon << " || " << modCon << std::endl
         << "Intelligence: " << effInt << " || " << modInt << std::endl
         << "Wisdom: " << effWis << " || " << modWis << std::endl
         << "Charisma: " << effCha << " || " << modCha << std::endl;

    return sstm.str();
}


std::string Character::equipedToString()
{
    std::stringstream sstm;

    sstm << "Currently wearing: " << std::endl;
    for (size_t i = 0; i < slot.size(); i++)
    {
        if( slot[i] != NULL)
        {
            sstm << "\t" << i << ": " << slot[i]->getName() << std::endl;
        }
    }

    return sstm.str();
}

std::string Character::invToString()
{
    std::stringstream sstm;

    sstm << "Currently in inventory:" << std::endl;
    for (size_t i = 0; i < inv.size(); i++)
    {
        if( inv[i] != NULL && !inv[i]->getEqStatus())
        {
            sstm << "\t" << inv[i]->getItemID() << ": " << inv[i]->getName() << std::endl;
        }
    }

    return sstm.str();
}

std::string Character::otherAttributesToString()
{
    std::stringstream sstm;

    sstm << "HP: " << curHP << "/" << maxHP << std::endl
         << "Armour Class: " << ac << std::endl
         << "Attack Bonus: ";
    for (size_t i = 0; i < attackBonus.size() - 1; i++)
    {
        sstm << attackBonus[i] << "/";
    }
    if (attackBonus.size() != 0)
    {
        sstm << attackBonus[attackBonus.size() - 1] << std::endl;
    }
    sstm << "Damage Bonus: " << meleeDmgBonus << std::endl;

    return sstm.str();
}

std::string Character::goldToString()
{
    return "Gold: " + std::to_string(gold) + "\n";
}

bool Character::saveCharacter(std::string filename)
{
    std::ofstream f(filename, std::ios::out);

    if (f.is_open())
    {
        f << name << std::endl
          << picture << std::endl
          << level << std::endl
          << baseStr << std::endl
          << baseDex << std::endl
          << baseCon << std::endl
          << baseInt << std::endl
          << baseWis << std::endl
          << baseCha << std::endl
          << effStr << std::endl
          << effDex << std::endl
          << effCon << std::endl
          << effInt << std::endl
          << effWis << std::endl
          << effCha << std::endl
          << modStr << std::endl
          << modDex << std::endl
          << modCon << std::endl
          << modInt << std::endl
          << modWis << std::endl
          << modCha << std::endl
          << ac << std::endl
             //          << baseAttackBonus[0] << std::endl
          << meleeDmgBonus << std::endl
          << maxHP << std::endl
          << curHP << std::endl
          << gold << std::endl;
        for (size_t i = 0; i < inv.size(); i++)
        {
            f << inv[i]->saveEquippable() << std::endl;
        }
        f.close();
        return true;
    }
    else
    {
        return false;
    }
}

// Load a character from file
bool Character::loadCharacter(std::string filename)
{
    std::ifstream f(filename, std::ios::in);

    if (f.is_open())
    {
        f >> name;
        f >> picture;
        f >> level;
        f >> baseStr;
        f >> baseDex;
        f >> baseCon;
        f >> baseInt;
        f >> baseWis;
        f >> baseCha;
        f >> effStr;
        f >> effDex;
        f >> effCon;
        f >> effInt;
        f >> effWis;
        f >> effCha;
        f >> modStr;
        f >> modDex;
        f >> modCon;
        f >> modInt;
        f >> modWis;
        f >> modCha;
        f >> ac;
        //        f >> baseAttackBonus[0];
        f >> meleeDmgBonus;
        f >> maxHP;
        f >> curHP;
        f >> gold;
        std::string item;
        while (std::getline(f, item)) {
            if (item != "") {
                Equippable* temp = Equippable::loadEquippable(item);
                inv.push_back(temp);
                if (temp->getEqStatus())
                    equip(*temp);
            }
        }
        f.close();
        updateAttackBonus();
        return true;
    }
    else
    {
        return false;
    }
}

void Character::attack(Character* target)
{
    for (size_t i = 0; i < attackBonus.size(); i++)
    {
        int r = roll(20, 1, attackBonus[i] + modStr);
        if (r >= target->ac)
        {
            int d = roll(8, 1, modStr);
            target->curHP -= d;
            attackinfo = this->name + " attacks " + target->name + ".\nRolled " + std::to_string(r) + " and dealt " + std::to_string(d) + " dmg!\n" + target->name + " has " + std::to_string(target->curHP) + "/" + std::to_string(target->maxHP) + " left.";
        }
        else
        {
            attackinfo = this->name + " attacks " + target->name + ".\nRolled " + std::to_string(r) + " and missed!";
        }
    }
}

//**********PRIVATE MEMBER FUNCTIONS**********//

// Rolls 4d6 and chooses the best three rolls
int Character::generateAbilityScore()
{
    int rolls[4];
    int smallestIndex = 0; //Index of the smallest roll
    int smallestVal = 24; //Biggest possible roll with 4d6
    int sum = 0;

    for(int i = 0; i < 4; i++)
    {
        rolls[i] = roll(6, 1, 0);
        if(rolls[i] < smallestVal)
        {
            smallestIndex = i;
            smallestVal = rolls[i];
        }
    }

    rolls[smallestIndex] = 0;

    for(int i = 0; i < 4; i++)
    {
        sum += rolls[i];
    }

    return sum;

}

// Based on DnD rules
int Character::calcModifier(int base)
{
    return static_cast<int>(floor((base - 10) / 2));
}

// Used by constructor to initialize and assign data members
void Character::assignAbilityScores()
{
    baseStr = effStr = generateAbilityScore();
    baseDex = effDex = generateAbilityScore();
    baseCon = effCon = generateAbilityScore();
    baseInt = effInt = generateAbilityScore();
    baseWis = effWis = generateAbilityScore();
    baseCha = effCha = generateAbilityScore();

    modStr = calcModifier(effStr);
    modDex = calcModifier(effDex);
    modCon = calcModifier(effCon);
    modInt = calcModifier(effInt);
    modWis = calcModifier(effWis);
    modCha = calcModifier(effCha);
}
