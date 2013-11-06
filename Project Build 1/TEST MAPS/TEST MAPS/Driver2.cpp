//Rewokred main to make it more readable


#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>

#include "Windows.h"
#include "dirent.h"

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

	std::cout << "\n" << player->characterSheetToString();
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
	playerLoaded = true;
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

	Grid map = Grid(height,width);

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
		map.setStart();


	std::cout<<"\n\n-Would you like to place the EXIT tile? (Y/N) ";
	std::cin>>yesOrNo;

	if(yesOrNo=='y' || yesOrNo=='Y')
		map.setEnd();
	//**********************************************************************************



	//********In this step the user places all necessary walls & occupied tiles*********
	std::cout<<"\n\n**************STEP 3*******************\n";

	//WALLS!
	std::cout<<"-Would you like to add some WALLS? (Y/N) ";
	std::cin>>yesOrNo;

	if(yesOrNo == 'Y' || yesOrNo == 'y')
	{
		do{

			map.setWalls();
			std::cout<<map.output()<<std::endl;

			std::cout<<"\nDo you want to add more WALLS? (Y/N) ";
			std::cin>>yesOrNo;

		}while(yesOrNo=='Y' || yesOrNo=='y');
	}

	//OCCUPIED!
	//std::cout<<"\n\n-Would you like to add some OCCUPIED cells? (Y/N)";
	//std::cin>>yesOrNo;

	//if(yesOrNo == 'Y' || yesOrNo == 'y')
	//{
	//	do{

	//		map.setOccu();
	//		std::cout<<map.output()<<std::endl;

	//		std::cout<<"\nDo you want to add more OCCUPIED tiles? (Y/N) ";
	//		std::cin>>yesOrNo;

	//	}while(yesOrNo=='Y' || yesOrNo=='y');
	//}
	//**********************************************************************************


	if( map.isValid())
	{
		std::cout << "Congratulations, your map is valid.\n";
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
