//Rewokred main to make it more readable


#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>

#include "Windows.h"

#include "E:\Google Drive\School\Fall 2013\COMP 345 - C++\COMP345-Project\Project Build 1\TEST MAPS\TEST MAPS\GridObserver.h"
#include "E:\Google Drive\School\Fall 2013\COMP 345 - C++\COMP345-Project\Project Build 1\TEST MAPS\TEST MAPS\InputManager.h"
#include "E:\Google Drive\School\Fall 2013\COMP 345 - C++\COMP345-Project\Project Build 1\TEST MAPS\TEST MAPS\Grid.h"
#include "E:\Google Drive\School\Fall 2013\COMP 345 - C++\COMP345-Project\Project Build 1\TEST MAPS\TEST MAPS\Fighter.h"
#include "E:\Google Drive\School\Fall 2013\COMP 345 - C++\COMP345-Project\Project Build 1\TEST MAPS\TEST MAPS\CharacterObserver.h"

void play();
void loadCharacter();
void createCharacter();
void loadMap();
void makeMap();

Fighter* player;
Grid* map;
bool playerLoaded = false;
bool mapLoaded = false;

int main()
{
	bool quit = false;

	do
	{
		puts("*****************");
		Sleep(350);
		puts("****Main Menu****");
		Sleep(350);
		puts("*****************\n\n");
		Sleep(350);

		puts("What would you like to do:\n\n1) Play\n2) Make a map\n3) Make a character\n4) Exit");

		int response;
		do
		{
			response = static_cast<int>(_getch()) - 48; // Get the int value of the character pressed
		} while (response < 1 || response > 4); //Make sure either 1, 2, or 3 was pressed

		switch (response)
		{
		case 1:
			play();
			break;
		case 2:
			makeMap();
			break;
		case 3:
			createCharacter();
			break;
		case 4:
			quit = true;
			puts("Thanks for playing!\n\n");
			break;
		} 
	} while(!quit);


}

void play()
{
	if(!playerLoaded)
	{
		puts("\n\nNo character is loaded yet...");
		loadCharacter();
	}
	if(!mapLoaded)
	{
		puts("\n\nNo map is loaded yet...");
		loadMap();
	}

	map->startGame(player);

	GridObserver obs(map);

	std:: vector <InputEvent> events;
	events.push_back(InputEvent("up",VK_UP));
	events.push_back(InputEvent("down",VK_DOWN));
	events.push_back(InputEvent("left",VK_LEFT));
	events.push_back(InputEvent("right",VK_RIGHT));
	events.push_back(InputEvent("character",0x43));
	events.push_back(InputEvent("quit",VK_ESCAPE));

	std::string move;

	//loops allowing for user to move player around the map
	//each move calls notify() and thus updating the map
	do
	{
		std::cout<< "your turn! \n";
		move = InputManager :: getInput(events);
		if (move == "character")
		{
			player->notify();
		}
		else
		{
			map->move(move);
		}
	}while( move != "quit");

	puts("Press any key to return to main menu...\n\n");
	_getch();
}

void createCharacter()
{
	std::string name;
	int level;
	puts("\n\nPlease enter a name:");
	std::cin >> name;
	puts("Please choose a starting level:");
	std::cin >> level;

	player = new Fighter(name, level);

	puts("Please enter filename to save new character:");
	std::string filename;
	std::cin >> filename;
	player->saveCharacter(filename);
}


void loadCharacter()
{
	std::string filename;
	puts("\n\nPlease enter filename of the character you'd like to load:");
	std::cin >> filename;
	player = new Fighter("", 1);
	if (!player->loadCharacter(filename))
	{
		puts("Could not load, generating new character...");
		createCharacter();
	}
	playerLoaded = true;
}

void makeMap()
{
	int width, height;
	char yesOrNo;
	std::cout<<"\n\n---------DUNGEONS & DRAGONS------------\n"
		<<"--------------MAP CREATOR--------------\n\n\n";


	//*************Promting the user for the map dimensions*****************************
	std::cout<<"**************STEP 1*******************\n";
	std::cout<<"Please enter the Width of the map: ";
	std::cin>>width;

	std::cout<<"Please enter the Height of the map: ";
	std::cin>>height;
	std::cout<<"\n\n";

	map = new Grid(height,width);

	std::cout<<"\nRemeber that,\n\n" 
		<<"\t-The vertical indices start at 0 increasing from top to bottom\n"
		<<"\t-The horizontal indices start at 0 increasing from left to right\n"
		<<"\nAlso,\n\n"
		<<"\t 'S' -> start   'E' -> Exit\n" 
		<<"\t '#' -> Wall    '!' -> Occupied\n"  
		<<"\t '@' -> Player  '-' -> Free\n";
	//**********************************************************************************





	//****************The user places the start & exit points***************************
	std::cout<<"\n\n\n**************STEP 2*******************\n";
	std::cout<<"-Would you like to place the START tile? (Y/N) ";
	std::cin>>yesOrNo;

	if(yesOrNo=='Y' || yesOrNo=='y')
		map->setStart();


	std::cout<<"\n\n-Would you like to place the EXIT tile? (Y/N) ";
	std::cin>>yesOrNo;

	if(yesOrNo=='y' || yesOrNo=='Y')
		map->setEnd();
	//**********************************************************************************



	//********In this step the user places all necessary walls & occupied tiles*********
	std::cout<<"\n\n**************STEP 3*******************\n";

	//WALLS!
	std::cout<<"-Would you like to add some WALLS? (Y/N) ";
	std::cin>>yesOrNo;

	if(yesOrNo == 'Y' || yesOrNo == 'y')
	{
		do{

			map->setWalls();
			std::cout<<map->output()<<std::endl;

			std::cout<<"\nDo you want to add more WALLS? (Y/N) ";
			std::cin>>yesOrNo;

		}while(yesOrNo=='Y' || yesOrNo=='y');
	}

	//Monster!
	std::cout<<"\n\n-Would you like to add some MONSTERS? (Y/N)";
	std::cin>>yesOrNo;

	if(yesOrNo == 'Y' || yesOrNo == 'y')
	{
		do{

			map->setMonster();
			std::cout<<map->output()<<std::endl;

			std::cout<<"\nDo you want to add more MONSTERS? (Y/N) ";
			std::cin>>yesOrNo;

		}while(yesOrNo=='Y' || yesOrNo=='y');
	}
	//**********************************************************************************


	if( map->isValid())
	{
		std::cout << "\n\nCongratulations, your map is valid.";
		puts("\n\nPlease enter filename to save your map:");
		std::string filename;
		std::cin >> filename;
		if (map->saveMap(filename))
		{
			puts("\n\Save seccessful!");
		}
		else
		{
			puts("\n\nSomething during the save process went wrong!");
		}

		//Basically, if this map is valid, it should SAVE to a folder designated
		//for saved maps, that can loaded upon pressing play on the main menu.
	}
	else
	{
		std::cout<<"\n\nUnfortunatley the map you have designed is not valid,\n";
		//exit(EXIT_FAILURE);
		//Shouldn't exit, just maybe display a message that will allow you to 
		//retry?
	}
}

void loadMap()
{
	std::string filename;
	puts("\n\nPlease enter filename of the map you'd like to load:");
	std::cin >> filename;
	map = new Grid();
	if (!map->loadMap(filename))
	{
		puts("Could not load, generating new map...");
		makeMap();
	}
	std::cout << map->output();
	mapLoaded = true;
}
