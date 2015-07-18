#pragma once

#include "GridContent.h"
#include "Item.h"
#include "Monster.h"
#include "Character.h"
//#include "Container.h"

class Cell
{
public:
    static enum state
    {
        START,
                EXIT,
                EMPTY,
                WALL,
                CHARACTER,
                MONSTER,
                MONSTERDEAD,
                CONTAINER,
                CONTAINEREMPTY
    };

public:
    Cell();
    Cell(state, GridContent* content = NULL);
    virtual ~Cell() {};

    bool canMoveOne() {return isStart() || isExit() || isEmpty() || isMonsterDead() || isContainerEmpty();}
    bool isStart() {return currentState == START;}
    bool isExit() {return currentState == EXIT;}
    bool isEmpty() {return currentState == EMPTY;}
    bool isWall() {return currentState == EMPTY;}
    bool isCharacter() {return currentState == CHARACTER;}
    bool isMonster() {return currentState == MONSTER;}
    bool isMonsterDead() {return currentState == MONSTERDEAD;}
    bool isContainer() {return currentState == CONTAINER;}
    bool isContainerEmpty() {return currentState == CONTAINEREMPTY;}

    Monster* getMonster();
    Character* getCharacter();
    Container* getContainer();

    state getState() {return currentState;}
    void setState(state s, GridContent* content);
    void setImage();
    char getImage() {return image;}

private:
    state currentState;
    GridContent* content;
    char image;
};

