#include <iostream>
#include <sstream>
#include "Grid.h"

using namespace std;

//Default Constructor
Grid::Grid()
{
	height = 5;
	width  = 5;

	grid = new Cell*[5];

	for(int i=0; i<5; i++)
		grid[i] = new Cell[5];

	for(int x=0; x<width; x++)
		for(int y=0; y<height; y++)
			grid[x][y] = Cell(NULL, Cell::state::EMPTY);

	startX=0;
	startY=height-1;
	endX=width-1;
	endY=0;

	playerX = startX;
	playerY = startY;

	grid[startX][startY] = Cell(NULL, Cell::state::START);
	grid[endX][endY] = Cell(NULL, Cell::state::EXIT);


}

//Constructor
Grid::Grid(int h, int w)
{
	height = h;
	width  = w;

	grid = new Cell*[w];

	for(int i=0; i<w; i++)
		grid[i] = new Cell[h];

	for(int x=0; x<width; x++)
		for(int y=0; y<height; y++)
			grid[x][y] = Cell(NULL, Cell::state::EMPTY);

	startX=0;
	startY=height-1;
	endX=width-1;
	endY=0;

	playerX=startX;
	playerY=startY;

	grid[startX][startY] = Cell(NULL, Cell::state::START);
	grid[endX][endY] = Cell(NULL, Cell::state::EXIT);

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


void Grid:: setOccu(GridContent* gc)
{
	int i,j;

	cout<<"\nEnter a vertical index ";
	cin>> j;

	cout<<"Enter a horizontal index ";
	cin>> i;

	if(grid[i][j].currentState == Cell::state::EMPTY)
	{
		grid[i][j].setState(Cell::state::OCCUPIED);
		grid[i][j].gc = gc;
	}
	else
		cout<<"\nSorry that tile is already occupied\n";


}
void Grid:: setWalls()
{
	int i,j;

	cout<<"\nEnter a vertical index ";
	cin>> j;

	cout<<"Enter a horizontal index ";
	cin>> i;

	if(grid[i][j].currentState == Cell::state::EMPTY)
		grid[i][j].setState(Cell::state::WALL);
	else 
		cout<<"\nSorry that tile is already occupied\n";
}
void Grid:: setStart()
{


	grid[startX][startY].setState(Cell::state::EMPTY);


	cout<<"\nEnter a vertical index ";
	cin>> startY;

	cout<<"Enter a horizontal index ";
	cin>> startX;

	playerX=startX;
	playerY=startY;

	grid[startX][startY].setState(Cell::state::START);

}
void Grid:: setEnd()
{
	grid[endX][endY].setState(Cell::state::EMPTY);

	cout<<"\nEnter a vertical index ";
	cin>> endY;

	cout<<"Enter a horizontal index ";
	cin>> endX;	

	grid[endX][endY].setState(Cell::state::EXIT);
}

void Grid:: startGame(Character* c)
{
	grid[startX][startY].gc = c;
	grid[startX][startY].setState(Cell::state::OCCUPIED);
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

void Grid:: move(string direction)
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
		if((playerY-1) >= 0 && 
			(grid[playerX][playerY-1].currentState == Cell::state::EMPTY||grid[playerX][playerY-1].currentState == Cell::state::EXIT|| grid[playerX][playerY-1].currentState == Cell::state::START))
		{
			playerY=playerY-1;
			grid[playerX][playerY].gc = temp;
			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
		}
	}

	else if(direction== "right")
	{
		if(playerX+1<width && 
			(grid[playerX+1][playerY].currentState == Cell::state::EMPTY||grid[playerX+1][playerY].currentState == Cell::state::EXIT|| grid[playerX+1][playerY].currentState == Cell::state::START))
		{
			playerX=playerX+1;
			grid[playerX][playerY].gc = temp;
			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
		}
	}

	else if(direction== "down")
	{
		if(playerY+1<height && ((grid[playerX][playerY+1].currentState == Cell::state::EMPTY)||(grid[playerX][playerY+1].currentState == Cell::state::EXIT)||(grid[playerX][playerY+1].currentState == Cell::state::START)))
		{
			playerY=playerY+1;
			grid[playerX][playerY].gc = temp;
			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
		}
	}

	else if(direction== "left")
	{
		if(playerX-1>=0 &&
			(grid[playerX-1][playerY].currentState == Cell::state::EMPTY||grid[playerX-1][playerY].currentState == Cell::state::EXIT|| grid[playerX-1][playerY].currentState == Cell::state::START))
		{
			playerX=playerX-1;
			grid[playerX][playerY].gc = temp;
			grid[playerX][playerY].setState(Cell::state::OCCUPIED);
		}
	}
	//*************************************************

	grid[playerX][playerY].gc = temp;
	grid[playerX][playerY].setState(Cell::state::OCCUPIED);

	notify();	

}

Cell Grid::at(int i, int j) {
    return grid[i][j];
}
