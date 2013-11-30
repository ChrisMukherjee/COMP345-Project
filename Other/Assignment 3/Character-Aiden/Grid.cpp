#include <iostream>
#include <sstream>
#include "Grid.h"
#include <fstream>
#include "windows.h"
#include "Fighter.h"

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
			grid[x][y] = Cell(NULL, Cell::state::EMPTY);

	// Set up initial walls around
	for (int i = 0; i < width; i++) {
		grid[i][0].setState(Cell::WALL);
		grid[i][height-1].setState(Cell::WALL);
	}
	for (int i = 0; i < height; i++) {
		grid[0][i].setState(Cell::WALL);
		grid[width-1][i].setState(Cell::WALL);
	}

	startX=0;
	startY=height-2;
	endX=width-2;
	endY=0;

	playerX = startX;
	playerY = startY;

	grid[startX][startY] = Cell(NULL, Cell::state::START);
	grid[endX][endY] = Cell(NULL, Cell::state::EXIT);


}

//Constructor
Grid::Grid(int w, int h)
{
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
			grid[x][y] = Cell(NULL, Cell::state::EMPTY);

	// Set up initial walls around
	for (int i = 0; i < width; i++) {
		grid[i][0].setState(Cell::WALL);
		grid[i][height-1].setState(Cell::WALL);
	}
	for (int i = 0; i < height; i++) {
		grid[0][i].setState(Cell::WALL);
		grid[width-1][i].setState(Cell::WALL);
	}
}
//destructor
Grid:: ~Grid()
{
	for (int i = 0; i < height; ++i)
	{
		delete[] grid[i];
	}
	delete grid;
}

//Validation method
bool Grid:: isValid()
{
	if (startX == -1 || startY == -1 || endX == -1 || endY == -1) {
		cout << endl << "Your map must have one (S)tart cell and one (E)nd cell.";
		Sleep(2000);
		return false;
	}

	//Using ideas from "the right hand rule" for maze travesal this method runs through the map
	//ensuring that the exit tile is always accesible from the start tile.
	int i = startX, j=startY;
	char** visited = new char*[width];

	for(int c=0; c<width; c++)
		visited[c] = new char[height];

	visited[i][j] = 'v';

	do
	{
		//goes to the right cell if possible
		if(i+1<width && (grid[i+1][j].currentState == Cell::state:: EMPTY||grid[i+1][j].currentState == Cell::state:: EXIT) && visited[i+1][j] != 'v' && visited[i+1][j] != 'T')
		{
			i++;
			visited[i][j]='v';
		}

		//otherwise goes up 1 cell, if possible
		else if(j-1>=0 && (grid[i][j-1].currentState == Cell::state:: EMPTY|| grid[i][j-1].currentState ==Cell::state:: EXIT) && visited[i][j-1] != 'v' && visited[i][j-1] != 'T')
		{
			j--;
			visited[i][j] = 'v';
		}

		//otherwise goes left 1 cell, if possible
		else if(i-1>=0 && (grid[i-1][j].currentState == Cell::state:: EMPTY||grid[i-1][j].currentState ==Cell::state:: EXIT) && visited[i-1][j] != 'v' && visited[i-1][j] != 'T')
		{
			i--;
			visited[i][j] = 'v';
		}

		//otherwise goes down 1 cell, if possible
		else if(j+1<height && (grid[i][j+1].currentState == Cell::state:: EMPTY ||grid[i][j+1].currentState == Cell::state:: EXIT) && visited[i][j+1] !='v' && visited[i][j+1] != 'T')
		{
			j++;
			visited[i][j] = 'v';
		}

		//if none of these are possible (i.e. trapped) the 'v' in visisted is replaced with a 'T'
		//then all the 'v's in the array visited are erased
		else
		{
			visited[i][j] = 'T';

			for(int x=0; x<width; x++)
			{
				for(int y=0; y<height; y++)
				{
					if(visited[x][y] == 'v')
						visited[x][y] = '-';
				}
			}

			i = startX;
			j = startY;	
		}


		if(visited[startX][startY] == 'T')
			return 0;
	}while(grid[i][j].currentState != Cell::state::EXIT);

	return 1;


}



//Tile Setters
//Since each type of tile has diiferent idetifiers on the map i decide to implement 
//a method for each

// Set cells to user defined value
bool Grid::setCell(int x, int y, char a) {
	// Cannot edit the corners of the map
	if ((x == 0 || x == width-1) && (y == 0 || y == height-1)) {
		// Print out helpful error message
		cout << endl << "Sorry, you cannot edit the corners of the map." << endl;
		return false;
	}
	// Start and End are added in a special way
	// Must make sure to only have one Start
	else if (a == 'S') {
		if (startX != -1 || startY != -1) {
			if ((startX == 0 || startX == width-1) || (startY == 0 || startY == height-1))
				grid[startX][startY].setState(Cell::state::WALL);
			else
				grid[startX][startY].setState(Cell::state::EMPTY);
		}
		grid[x][y].setState(Cell::state::START);
		startX = x;
		startY = y;
		return true;
	}
	// Must make sure to only have one End
	else if (a == 'E') {
		if (endX != -1 || endY != -1) {
			if ((endX == 0 || endX == width-1) || (endY == 0 || endY == height-1))
				grid[endX][endY].setState(Cell::state::WALL);
			else
				grid[endX][endY].setState(Cell::state::EMPTY);
		}
		grid[x][y].setState(Cell::state::EXIT);
		endX = x;
		endY = y;
		return true;
	}
	// Can only add doors or walls to the edges
	else if ((x == 0 || x == width-1) || (y == 0 || y == height-1)) {
		if (a == '#') {
			// Reset Start and End locations, if replacing one
			if (grid[x][y].currentState == Cell::START) {
				startX = -1;
				startY = -1;
			}
			if (grid[x][y].currentState == Cell::EXIT) {
				endX = -1;
				endY = -1;
			}
			grid[x][y].setState(Cell::state::WALL);
		}
		else {
			// Print out helpful error message
			cout << endl << "Invalid character! You can only add a (S)tart cell, an (E)nd cell, or walls (#) to the edges of the map." << endl;
			return false;
		}
		return true;
	}
	// Any other acceptable character can be added in the map
	else if (a == '#') {
		// Reset Start and End locations, if replacing one
		if (grid[x][y].currentState == Cell::START) {
			startX = -1;
			startY = -1;
		}
		if (grid[x][y].currentState == Cell::EXIT) {
			endX = -1;
			endY = -1;
		}
		grid[x][y].setState(Cell::state::WALL);
		return true;
	}
	else if (a == '.') {
		// Reset Start and End locations, if replacing one
		if (grid[x][y].currentState == Cell::START) {
			startX = -1;
			startY = -1;
		}
		if (grid[x][y].currentState == Cell::EXIT) {
			endX = -1;
			endY = -1;
		}
		grid[x][y].setState(Cell::state::EMPTY);
		return true;
	}
	else if (a == 'C') {
		// Reset Start and End locations, if replacing one
		if (grid[x][y].currentState == Cell::START) {
			startX = -1;
			startY = -1;
		}
		if (grid[x][y].currentState == Cell::EXIT) {
			endX = -1;
			endY = -1;
		}
		grid[x][y].setState(Cell::state::CHEST);
		return true;
	}
	else if (a == 'M') {
		// Reset Start and End locations, if replacing one
		if (grid[x][y].currentState == Cell::START) {
			startX = -1;
			startY = -1;
		}
		if (grid[x][y].currentState == Cell::EXIT) {
			endX = -1;
			endY = -1;
		}
		grid[x][y].setState(Cell::state::MONSTER);
		return true;
	}
	else {
		// Print out helpful error message
		cout << endl << "Invalid character! Please enter an acceptable character." << endl;
		return false;
	}
	return true;
};

void Grid:: startGame(Character* c)
{
	grid[startX][startY].gc = c;
	grid[startX][startY].setState(Cell::state::OCCUPIED);
	playerX = startX;
	playerY = startY;
	this->output();
}


//Output Method

string Grid:: output()
{
	std::stringstream sstm;
	sstm<<"\n\n";

	for(int j=0; j<height; j++)
	{
		//cout<<"\t\t\t";
		for(int i=0; i<width; i++)
		{
			sstm<<"| "<<grid[i][j].image<<" | ";
		}

		sstm<<"\n\n";
	}

	return sstm.str();
}

bool Grid:: move(string direction)
{
	//std::cout << (playerY < height);

	GridContent* temp = grid[playerX][playerY].gc;

	//******** Do Not erase Start & End Tiles*******
	if(playerX==startX && playerY==startY)
		grid[playerX][playerY].setState(Cell::state::START);

	else if(playerX==endX && playerY==endY)
		grid[playerX][playerY].setState(Cell::state::EXIT);

	else
		grid[playerX][playerY].setState(Cell::state::EMPTY);
	//**********************************************




	//*****Define What Happens With Each Input******
	if(direction== "up")
	{
		if((playerY-1) >= 0
			&& (grid[playerX][playerY-1].currentState == Cell::state::EMPTY
			 || grid[playerX][playerY-1].currentState == Cell::state::EXIT
			 || grid[playerX][playerY-1].currentState == Cell::state::START))
		{
			playerY=playerY-1;
			grid[playerX][playerY].gc = temp;
			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
		}
		else if (grid[playerX][playerY-1].currentState == Cell::state::CHEST)
		{
			dynamic_cast<Fighter*>(temp)->pickUp(new Equippable("Sword",Equippable::WEAPON));
			grid[playerX][playerY-1].setState(Cell::state::EMPTY);
			this->notify();
		}
	}

	else if(direction== "right")
	{
		if(playerX+1<width
			&& 
			(grid[playerX+1][playerY].currentState == Cell::state::EMPTY
			|| grid[playerX+1][playerY].currentState == Cell::state::EXIT
			|| grid[playerX+1][playerY].currentState == Cell::state::START))
		{
			playerX=playerX+1;
			grid[playerX][playerY].gc = temp;
			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
		}
		else if (grid[playerX+1][playerY].currentState == Cell::state::CHEST)
		{
			dynamic_cast<Fighter*>(temp)->pickUp(new Equippable("Sword",Equippable::WEAPON));
			grid[playerX+1][playerY].setState(Cell::state::EMPTY);
			this->notify();
		}
	}

	else if(direction== "down")
	{
		if(playerY+1<height
			&& ((grid[playerX][playerY+1].currentState == Cell::state::EMPTY)
			  ||(grid[playerX][playerY+1].currentState == Cell::state::EXIT)
			  ||(grid[playerX][playerY+1].currentState == Cell::state::START)))
		{
			playerY=playerY+1;
			grid[playerX][playerY].gc = temp;
			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
		}
		else if (grid[playerX][playerY+1].currentState == Cell::state::CHEST)
		{
			dynamic_cast<Fighter*>(temp)->pickUp(new Equippable("Sword",Equippable::WEAPON));
			grid[playerX][playerY+1].setState(Cell::state::EMPTY);
			this->notify();
		}
	}

	else if(direction== "left")
	{
		if(playerX-1>=0
			&& (grid[playerX-1][playerY].currentState == Cell::state::EMPTY
			 || grid[playerX-1][playerY].currentState == Cell::state::EXIT
			 || grid[playerX-1][playerY].currentState == Cell::state::START))
		{
			playerX=playerX-1;
			grid[playerX][playerY].gc = temp;
			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
		}
		else if (grid[playerX-1][playerY].currentState == Cell::state::CHEST)
		{
			dynamic_cast<Fighter*>(temp)->pickUp(new Equippable("Sword",Equippable::WEAPON));
			grid[playerX-1][playerY].setState(Cell::state::EMPTY);
			this->notify();
		}
	}
	//*************************************************

	grid[playerX][playerY].gc = temp;
	grid[playerX][playerY].setState(Cell::state::OCCUPIED);

	notify();


	if (playerX == endX && playerY == endY)
	{
		return true;
	}
	return false;
}

bool Grid::saveMap()
{
	std::string filename;
	puts("\n\nPlease enter filename of the map you'd like to save:");
	std::cin >> filename;
	std::ofstream f(filename, std::ios::out);

	if (f.is_open())
	{
		f << width << std::endl << height << std::endl;

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (grid[j][i].currentState == Cell::state::EMPTY)
				{
					f << '.' << " "; //Special case for empty cells, to help with loading
				}
				else{
					f << grid[j][i].image << " ";
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

Grid* Grid::loadMap()
{
	std::string filename;
	puts("\n\nPlease enter filename of the map you'd like to load:");
	std::cin >> filename;
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

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; j++)
			{
				char temp;
				f >> temp;
				switch (temp)
				{
				case '.':
					map->grid[j][i].setState(Cell::state::EMPTY);
					break;
				case 'S':
					map->grid[j][i].setState(Cell::state::START);
					map->startX = j;
					map->startY = i;
					break;
				case 'E':
					map->grid[j][i].setState(Cell::state::EXIT);
					map->endX = j;
					map->endY = i;
					break;
				case '#':
					map->grid[j][i].setState(Cell::state::WALL);
					break;
				case 'M':
					map->grid[j][i].setState(Cell::state::MONSTER);
					break;
				case 'C':
					map->grid[j][i].setState(Cell::state::CHEST);
					map->grid[j][i].it = new Equippable("Swrod", Equippable::WEAPON);
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



