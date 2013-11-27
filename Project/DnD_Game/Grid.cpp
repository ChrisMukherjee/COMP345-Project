#include <iostream>
#include <sstream>
#include "Grid.h"
#include <fstream>
#include "windows.h"
#include "Fighter.h"
#include <cmath>
#include <algorithm>

using namespace std;

//Default Constructor
Grid::Grid()
{
	height = 5+2;
	width  = 5+2;


	grid = new Cell*[width];

	for(int i=0; i<width; i++)
		grid[i] = new Cell[height];

	for(int x=0; x<width; x++)
		for(int y=0; y<height; y++)
			grid[x][y] = Cell(Cell::state::EMPTY,NULL);

	// Set up initial walls around
	for (int i = 0; i < width; i++) {
		grid[i][0].setState(Cell::WALL, NULL);
		grid[i][height-1].setState(Cell::WALL, NULL);
	}
	for (int i = 0; i < height; i++) {
		grid[0][i].setState(Cell::WALL, NULL);
		grid[width-1][i].setState(Cell::WALL, NULL);
	}

	startX=0;
	startY=height-2;
	endX=width-2;
	endY=0;

	playerX = startX;
	playerY = startY;

	//We don't need to mark those cells as start or exit
	//We will just keep those as pairs of numbers in the map
	//grid[startX][startY] = Cell(Cell::state::START, NULL);
	//grid[endX][endY] = Cell(Cell::state::EXIT,NULL);


}

//Constructor
Grid::Grid(int w, int h)
{
	numMonsters = 0;

	height = h+2;
	width  = w+2;
	startX = -1;
	startY = -1;
	endX = -1;
	endY = -1;

	grid = new Cell*[width];

	for(int i=0; i<width; i++)
		grid[i] = new Cell[height];

	for(int x=0; x<width; x++)
		for(int y=0; y<height; y++)
			grid[x][y] = Cell(Cell::state::EMPTY, NULL);

	// Set up initial walls around
	for (int i = 0; i < width; i++) {
		grid[i][0].setState(Cell::WALL, NULL);
		grid[i][height-1].setState(Cell::WALL, NULL);
	}
	for (int i = 0; i < height; i++) {
		grid[0][i].setState(Cell::WALL, NULL);
		grid[width-1][i].setState(Cell::WALL, NULL);
	}
}
//destructor
Grid:: ~Grid()
{
    for (int i = 0; i < width; ++i)
	{
		delete[] grid[i];
	}
    delete[] grid;
}

bool sortByDex(Character* i, Character* j) {return i->initiative > j->initiative;}

void Grid::startGame(Character* c)
{
	grid[startX][startY].setState(Cell::CHARACTER, c);
	c->x = startX;
	c->y = startY;
	playerX = startX;
	playerY = startY;
	actors.push_back(c);

	for(size_t i = 0; i < actors.size(); i++)
	{
		actors[i]->initiative = roll(20) + actors[i]->modDex;
	}

	std::sort(actors.begin(), actors.end(), sortByDex);

//	this->output();
}


//Output Method

string Grid::output()
{
    std::stringstream sstm;
    sstm<<"\n\n";

    for(int j=0; j<height; j++)
    {
        //cout<<"\t\t\t";
        for(int i=0; i<width; i++)
        {
            sstm<<" "<<grid[i][j].getImage()<<"  ";
        }

        sstm<<"\n\n";
    }

    return sstm.str();
}

void Grid::move(Monster* monster, int destX, int destY)
{
	Cell* oldTile = &grid[monster->x][monster->y];
	Cell* newTile = &grid[destX][destY];
	oldTile->setState(Cell::EMPTY, NULL);
	newTile->setState(Cell::MONSTER, monster);
	monster->x = destX;
	monster->y = destY;
}

void Grid::move(Fighter* player, int destX, int destY)
{
	Cell* oldTile = &grid[player->x][player->y];
	Cell* newTile = &grid[destX][destY];
	oldTile->setState(Cell::EMPTY, NULL);
	newTile->setState(Cell::CHARACTER, player);
	player->x = destX;
	player->y = destY;
}

bool Grid::getMove(Character* actor, string dir, bool isPlayer)
{
	Cell* oldTile = &grid[actor->x][actor->y]; //This is the current tile the player is on
	Cell* newTile; //This will be the prospective tile to move to

	bool moved = false;

	if (dir == "up")
	{
		newTile = &grid[actor->x][actor->y - 1];
		if( (actor->y - 1 >= 0) && (newTile->canMoveOne()) )
		{
			if(isPlayer)
			{
				move(dynamic_cast<Fighter*>(actor), actor->x, actor->y - 1);
			}
			else
			{
				move(dynamic_cast<Monster*>(actor), actor->x, actor->y - 1);
			}
			moved = true;
		} //Need cases for chest!!!
	}
	else if (dir == "down")
	{
		newTile = &grid[actor->x][actor->y + 1];
		if( (actor->y + 1 < height) && (newTile->canMoveOne()) )
		{
			if(isPlayer)
			{
				move(dynamic_cast<Fighter*>(actor), actor->x, actor->y + 1);
			}
			else
			{
				move(dynamic_cast<Monster*>(actor), actor->x, actor->y + 1);
			}
			moved = true;
		}
	}
	else if (dir == "right")
	{
		newTile = &grid[actor->x + 1][actor->y];
		if( (actor->x + 1 < width) && (newTile->canMoveOne()) )
		{
			if(isPlayer)
			{
				move(dynamic_cast<Fighter*>(actor), actor->x + 1, actor->y);
			}
			else
			{
				move(dynamic_cast<Monster*>(actor), actor->x + 1, actor->y);
			}
			moved = true;
		}
	}
	else if (dir == "left")
	{
		newTile = &grid[actor->x - 1][actor->y];
		if( (actor->x - 1 >= 0) && (newTile->canMoveOne()) )
		{
			if(isPlayer)
			{
				move(dynamic_cast<Fighter*>(actor), actor->x - 1, actor->y);
			}
			else
			{
				move(dynamic_cast<Monster*>(actor), actor->x - 1, actor->y);
			}
			moved = true;
		}
	}

	if (grid[startX][startY].isEmpty())
	{
		grid[startX][startY].setState(Cell::START, NULL);
	}
	if (grid[endX][endY].isEmpty())
	{
		grid[endX][endY].setState(Cell::EXIT, NULL);
	}

	notify();

	return moved;
}

//bool Grid:: move(string direction) /////////This needs to be completely reworked
//{
//	//std::cout << (playerY < height);
//
//	GridContent* temp = grid[playerX][playerY].gc;
//
//	//******** Do Not erase Start & End Tiles*******
//	if(playerX==startX && playerY==startY)
//		grid[playerX][playerY].setState(Cell::state::START);
//
//	else if(playerX==endX && playerY==endY)
//		grid[playerX][playerY].setState(Cell::state::EXIT);
//
//	else
//		grid[playerX][playerY].setState(Cell::state::EMPTY);
//	//**********************************************
//
//
//
//
//	//*****Define What Happens With Each Input******
//	if(direction== "up")
//	{
//		if((playerY-1) >= 0
//			&& (grid[playerX][playerY-1].currentState == Cell::state::EMPTY
//			|| grid[playerX][playerY-1].currentState == Cell::state::EXIT
//			|| grid[playerX][playerY-1].currentState == Cell::state::START))
//		{
//			playerY=playerY-1;
//			grid[playerX][playerY].gc = temp;
//			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
//		}
//		else if (grid[playerX][playerY-1].currentState == Cell::state::CHEST)
//		{
//			dynamic_cast<Fighter*>(temp)->pickUp(new Equippable("Sword",Equippable::WEAPON));
//			grid[playerX][playerY-1].setState(Cell::state::EMPTY);
//			this->notify();
//		}
//	}
//
//	else if(direction== "right")
//	{
//		if(playerX+1<width
//			&& 
//			(grid[playerX+1][playerY].currentState == Cell::state::EMPTY
//			|| grid[playerX+1][playerY].currentState == Cell::state::EXIT
//			|| grid[playerX+1][playerY].currentState == Cell::state::START))
//		{
//			playerX=playerX+1;
//			grid[playerX][playerY].gc = temp;
//			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
//		}
//		else if (grid[playerX+1][playerY].currentState == Cell::state::CHEST)
//		{
//			dynamic_cast<Fighter*>(temp)->pickUp(new Equippable("Sword",Equippable::WEAPON));
//			grid[playerX+1][playerY].setState(Cell::state::EMPTY);
//			this->notify();
//		}
//	}
//
//	else if(direction== "down")
//	{
//		if(playerY+1<height
//			&& ((grid[playerX][playerY+1].currentState == Cell::state::EMPTY)
//			||(grid[playerX][playerY+1].currentState == Cell::state::EXIT)
//			||(grid[playerX][playerY+1].currentState == Cell::state::START)))
//		{
//			playerY=playerY+1;
//			grid[playerX][playerY].gc = temp;
//			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
//		}
//		else if (grid[playerX][playerY+1].currentState == Cell::state::CHEST)
//		{
//			dynamic_cast<Fighter*>(temp)->pickUp(new Equippable("Sword",Equippable::WEAPON));
//			grid[playerX][playerY+1].setState(Cell::state::EMPTY);
//			this->notify();
//		}
//	}
//
//	else if(direction== "left")
//	{
//		if(playerX-1>=0
//			&& (grid[playerX-1][playerY].currentState == Cell::state::EMPTY
//			|| grid[playerX-1][playerY].currentState == Cell::state::EXIT
//			|| grid[playerX-1][playerY].currentState == Cell::state::START))
//		{
//			playerX=playerX-1;
//			grid[playerX][playerY].gc = temp;
//			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
//		}
//		else if (grid[playerX-1][playerY].currentState == Cell::state::CHEST)
//		{
//			dynamic_cast<Fighter*>(temp)->pickUp(new Equippable("Sword",Equippable::WEAPON));
//			grid[playerX-1][playerY].setState(Cell::state::EMPTY);
//			this->notify();
//		}
//	}
//	//*************************************************
//
//	grid[playerX][playerY].gc = temp;
//	grid[playerX][playerY].setState(Cell::state::OCCUPIED);
//
//	notify();
//
//
//	if (playerX == endX && playerY == endY)
//	{
//		return true;
//	}
//	return false;
//}

bool Grid::saveMap()
{
	std::string filename;
	puts("\n\nPlease enter filename of the map you'd like to save:");
	std::cin >> filename;
	std::ofstream f(filename, std::ios::out);

	if (f.is_open())
	{
		f << width << std::endl << height << std::endl << numMonsters << std::endl;

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (grid[j][i].isEmpty())
				{
					f << '.' << " "; //Special case for empty cells, to help with loading
				}
				else{
					f << grid[j][i].getImage() << " ";
				}
			}
			f << std::endl;
		} 
		f.close();
		return true;
	}
	else
	{
		return false;
	}
}

Grid* Grid::loadMap(std::string filename, int characterLevel)
{
	std::ifstream f(filename, std::ios::in);

	if (f.is_open())
	{
		int width, height;
		f >> width >> height;

		Grid* map = new Grid(width - 2, height - 2);

		map->grid = new Cell*[width];

		for (int i=0; i < width; i++)
		{
			map->grid[i] = new Cell[height];
		}

		f >> map->numMonsters;

		int levelPerMonster = ceil(static_cast<float>(characterLevel) / map->numMonsters);
		int numM = 0;
		Monster* m;

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; j++)
			{
				char temp;
				f >> temp;
				switch (temp)
				{
				case '.':
					map->grid[j][i].setState(Cell::state::EMPTY, NULL);
					break;
				case 'S':
					map->grid[j][i].setState(Cell::state::START, NULL);
					map->startX = j;
					map->startY = i;
					break;
				case 'E':
					map->grid[j][i].setState(Cell::state::EXIT, NULL);
					map->endX = j;
					map->endY = i;
					break;
				case '#':
					map->grid[j][i].setState(Cell::state::WALL, NULL);
					break;
				case 'M':
					m = new Monster("Rat", levelPerMonster);
					map->grid[j][i].setState(Cell::state::MONSTER, m);
					m->x = i;
					m->y = j;
					map->actors.push_back(m);
					break;
				case 'C':
					map->grid[j][i].setState(Cell::state::CONTAINER, NULL); //THIS IS WHERE NEW CONT GETS GEN'D
					//map->grid[j][i].it = new Equippable("Swrod", Equippable::WEAPON);
					break;
				}
			}
		}
		f.close();
        return map;
	}
	else
	{
		return NULL;
	}

}

bool Grid::inRange(int srcX, int srcY, int tarX, int tarY, int range)
{
	int d = floor(sqrt(((tarX - srcX) * (tarX - srcX)) + ((tarY - srcY) * (tarY - srcY))));
	std::cout << d << std::endl;
	if (d <= range)
	{
		return true;
	}
	return false;
}

char** Grid::getGrid()
{
    char** tmp = new char*[width];

    for(int i=0; i<width; i++)
        tmp[i] = new char[height];

    for(int i=0; i<width; i++) {
        for(int j=0; j<height; j++) {
            tmp[i][j] = grid[i][j].getImage();
        }
    }
    return tmp;
}
