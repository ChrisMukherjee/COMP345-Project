#include <iostream>
#include <sstream>
#include "Grid.h"

using namespace std;

//Default Constructor
Grid::Grid()
{
	Grid:: height = 5;
	Grid:: width  = 5;

	Grid:: grid = new char*[5];

	for(int i=0; i<5; i++)
		grid[i] = new char[5];

	for(int x=0; x<width; x++)
		for(int y=0; y<height; y++)
			grid[x][y] = '-';
	
	startX=0;
	startY=height-1;
	endX=width-1;
	endY=0;

	playerX = startX;
	playerY = startY;
	
	grid[startX][startY] = 'S';
	grid[endX][endY] = 'E';

		
}

//Constructor
Grid::Grid(int h, int w)
{
	Grid:: height = h;
	Grid:: width  = w;

	Grid:: grid = new char*[w];

	for(int i=0; i<w; i++)
		grid[i] = new char[h];
	
	for(int x=0; x<width; x++)
		for(int y=0; y<height; y++)
			grid[x][y] = '-';

	startX=0;
	startY=height-1;
	endX=width-1;
	endY=0;

	playerX=startX;
	playerY=startY;
	
	grid[startX][startY] = 'S';
	grid[endX][endY] = 'E';
		
}
//destructor
Grid:: ~Grid()
{
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
		if(i+1<width && (grid[i+1][j] == '-'||grid[i+1][j] =='E') && visited[i+1][j] != 'v' && visited[i+1][j] != 'T')
		{
			i++;
			visited[i][j]='v';
		}

		//otherwise goes up 1 cell, if possible
		else if(j-1>=0 && (grid[i][j-1] == '-'|| grid[i][j-1] =='E') && visited[i][j-1] != 'v' && visited[i][j-1] != 'T')
		{
			j--;
			visited[i][j] = 'v';
		}

		//otherwise goes left 1 cell, if possible
		else if(i-1>=0 && (grid[i-1][j] == '-'||grid[i-1][j] =='E') && visited[i-1][j] != 'v' && visited[i-1][j] != 'T')
		{
			i--;
			visited[i][j] = 'v';
		}

		//otherwise goes down 1 cell, if possible
		else if(j+1<height && (grid[i][j+1] == '-'||grid[i][j+1] == 'E') && visited[i][j+1] !='v' && visited[i][j+1] != 'T')
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
	}while(grid[i][j] != 'E');

	return 1;


}



//Tile Setters
//Since each type of tile has diiferent idetifiers on the map i decide to implement 
//a method for each


void Grid:: setOccu()
{
	int i,j;

	cout<<"\nEnter a vertical index ";
	cin>> j;

	cout<<"Enter a horizontal index ";
	cin>> i;
	
	if(grid[i][j]== '-')
		grid[i][j]='!';
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

	if(grid[i][j] == '-')
		grid[i][j]='#';
	else 
		cout<<"\nSorry that tile is already occupied\n";
}
void Grid:: setStart()
{
	

	grid[startX][startY]= '-';


	cout<<"\nEnter a vertical index ";
	cin>> startY;

	cout<<"Enter a horizontal index ";
	cin>> startX;

	playerX=startX;
	playerY=startY;
	
	grid[startX][startY]='S';
	
}
void Grid:: setEnd()
{
	grid[endX][endY] = '-';

	cout<<"\nEnter a vertical index ";
	cin>> endY;

	cout<<"Enter a horizontal index ";
	cin>> endX;	

	grid[endX][endY]='E';
	
}

void Grid:: startGame()
{
	grid[startX][startY] = '@';
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
			sstm<<"| "<<grid[i][j]<<" | ";
		}
		
		sstm<<"\n\n";
	}

	return sstm.str();
}

void Grid:: move(char direction)
{
	if(playerX==startX && playerY==startY)
		grid[playerX][playerY] = 'S';
	else
		grid[playerX][playerY] = '-';

	
	if(direction=='w' || direction=='W')
	{
		playerY=playerY-1;
		grid[playerX][playerY] = '@';
	}

	else if(direction=='d' || direction=='D')
	{
		playerX=playerX+1;
		grid[playerX][playerY]='@';
	}

	else if(direction=='s' || direction=='S')
	{
		playerY=playerY+1;
		grid[playerX][playerY]='@';
	}

	else if(direction=='a' || direction=='A')
	{
		playerX=playerX-1;
		grid[playerX][playerY]='@';
	}

	notify();	

}

/*bool Grid:: equals(Grid otherMap)
{
	for(int j=0; j<height; j++)
	{
		//cout<<"\t\t\t";
		for(int i=0; i<width; i++)
		{
			if(grid[i][j] != otherMap.gridAt(i,j))
				return false;
		}
	}

	return true;
}*/