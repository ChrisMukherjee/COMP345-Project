//Rewokred main to make it more readable

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <ctime>

#include "Windows.h"

#include "GridObserver.h"
#include "InputManager.h"
#include "Grid.h"
#include "Fighter.h"
#include "CharacterObserver.h"

#include "splashdialog.h"
#include <QApplication>

void play();
void playerTurn();
void loadCharacter();
void createCharacter();
//void loadMap();
//void makeMap();

bool playerLoaded = false;
bool mapLoaded = false;
std::string filename;
std::vector <InputEvent> events;

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned>(time(NULL)));

    QApplication a(argc, argv);
    SplashDialog sp;
    sp.show();

//	bool quit = false;

//	do
//	{
//		system("CLS");
//		puts("*****************");
//		Sleep(350);
//		puts("****Main Menu****");
//		Sleep(350);
//		puts("*****************\n\n");
//		Sleep(350);

//		puts("What would you like to do:\n\n1) Play\n2) Make a map\n3) Make a character\n4) Exit");

//		int response;
//		do
//		{
//			response = static_cast<int>(_getch()) - 48; // Get the int value of the character pressed
//		} while (response < 1 || response > 4); //Make sure either 1, 2, 3 or 4 was pressed

//		switch (response)
//		{
//		case 1:
//			play();
//			break;
//		case 2:
//			makeMap();
//			break;
//		case 3:
//			createCharacter();
//			break;
//		case 4:
//			system("CLS");
//			quit = true;
//			puts("\n\nThanks for playing!\n\n");
//			break;
//		}
//	} while(!quit);

    return a.exec();
}

//void play()
//{
//	system("CLS");
//	if(!playerLoaded)
//	{
//		puts("\n\nNo character is loaded yet...");
//		loadCharacter();
//	}
//	if(!mapLoaded)
//	{
//		puts("\n\nNo map is loaded yet...");
//		loadMap();
//	}

//	if (mapLoaded && playerLoaded)
//	{
//    map->startGame(player);
//	}

//    GridObserver gObs(map);
//	CharacterObserver cObs(*player);

//    CharacterObserver* mObs = new CharacterObserver[map->actors.size()];

//    for (size_t i = 0; i < map->actors.size(); i++)
//	{
//        map->actors[i]->attach(&mObs[i]);
//	}

//	events.push_back(InputEvent("up",VK_UP));
//	events.push_back(InputEvent("down",VK_DOWN));
//	events.push_back(InputEvent("left",VK_LEFT));
//	events.push_back(InputEvent("right",VK_RIGHT));
//	events.push_back(InputEvent("character",0x43));
//	events.push_back(InputEvent("map", 0x4d));
//	events.push_back(InputEvent("quit",VK_ESCAPE));

//	while (!map->isEnd(player->x, player->y))
//	{
//		for (size_t i = 0; i < map->actors.size(); i++)
//		{
//			if (map->actors[i]->name == "Rat")
//			{
//				int d = roll(4);
//				if (d == 1) {map->getMove(map->actors[i], "up", false);}
//				else if (d == 2) {map->getMove(map->actors[i], "down", false);}
//				else if (d == 3) {map->getMove(map->actors[i], "right", false);}
//				else if (d == 4) {map->getMove(map->actors[i], "left", false);}
//			}
//			else
//			{
//				playerTurn();
//			}
//		}
//	}
//}

//void playerTurn()
//{
//	std::string move;
//	bool moved = false;

//	std::cout<< "your turn! \n";
//	do
//	{
//		move = InputManager :: getInput(events);
//		if (move == "character")
//		{
//			for (size_t i = 0; i < map->actors.size(); i++)
//			{
//				std::cout << map->actors[i]->characterSheetToString();
//			}
//		}
//		else if (move == "map")
//		{
//			map->notify();
//		}
//		else
//		{
//			moved = map->getMove(player, move, true);
//		}
//	} while (!moved);
//	//if (onExit)
//	//{
//	//	system("CLS");
//	//	player->levelUp();
//	//	puts("Congratulations! You have beaten the level. Your character increases in strength!");
//	//	std::cout << '\a';
//	//	Sleep(2500);
//	//	player->notify();
//	//	Sleep(2500);
//	//	player->saveCharacter(filename);
//	//	mapLoaded = false;
//	//	playerLoaded = false;
//	//}
//}

//void createCharacter()
//{
//	system("CLS");
//	std::string name;
//	int level;
//	puts("\n\nPlease enter a name:");
//	std::cin >> name;
//	puts("Please choose a starting level:");
//	std::cin >> level;

//	player = new Fighter(name, level);

//	puts("Please enter filename to save new character:");
//	std::string filename;
//	std::cin >> filename;
//	player->saveCharacter(filename);
//}


//void loadCharacter()
//{
//	system("CLS");
//	//std::string filename;
//	puts("\n\nPlease enter filename of the character you'd like to load:");
//	std::cin >> filename;
//	player = new Fighter("", 1);
//	if (!player->loadCharacter(filename))
//	{
//		puts("Could not load, generating new character...");
//		createCharacter();
//	}
//	playerLoaded = true;
//}

//void makeMap()
//{
//	system("CLS");
//	int width, height;
//	std::cout<<"\n\n---------DUNGEONS & DRAGONS------------\n"
//		<<"--------------MAP CREATOR--------------\n\n\n";


//	//*************Promting the user for the map dimensions*****************************
//	std::cout<<"Please enter the Width of the map: ";
//	std::cin>>width;

//	std::cout<<"Please enter the Height of the map: ";
//	std::cin>>height;
//	std::cout<<"\n\n";

//	map = new Grid(width, height);

//	while (1) {
//		// Output map so user can see his/her changes
//		system("CLS");
//		std::cout << map->output();
//		bool checkValid = false;

//		while (!checkValid) {
//			char editChar = ' ';
//			int editWidth = 0;
//			int editHeight = 0;
//			// Reset variable to false
//			bool completed = false;
//			bool validate = false;

//			std::cout << std::endl << "Options:" << std::endl << " # : Wall" << std::endl << " S : Start" << std::endl << " E : End" << std::endl << " C : Chest" << std::endl << " M : Monster" << std::endl << " . : Empty Space" << std::endl;
//			std::cout << std::endl << "You can also enter Q to quit and discard your map, V to validate your map, or K to validate and keep your map." << std::endl;
//			std::cout << std::endl << "Enter an acceptable character: ";
//			std::cin >> editChar;

//			// If user enters Q, quit program
//			if (editChar == 'Q' || editChar == 'q')
//				return;

//			// If user enters V, run validation code
//			if (editChar == 'V' || editChar == 'v') {
//				validate = true;
//			}

//			// If user enters S, run validation code and save
//			if (editChar == 'K' || editChar == 'k') {
//				validate = true;
//				completed = true;
//			}

//			// Run validation method and output message if user requests
//			if (validate) {
//				if (map->isValid())
//				{
//					puts("\nCongrats, your map is valid!");
//					if (completed) {
//						map->saveMap();
//						return;
//					}
//				}
//				else
//				{
//					std::cout << std::endl << "Sorry, this map is invalid. Please review it and fix any errors." << std::endl << std::endl << std::endl;
//				}
//			}
//			else {
//				do {
//					std::cout << std::endl << "Enter the horizontal index of the cell you wish to edit: ";
//					std::cin >> editWidth;
//					// Make sure the index is valid
//					if (editWidth > (map->getWidth()-1) || editWidth < 0)
//						std::cout << "Invalid width! Please try again." << std::endl;
//				}
//				while (editWidth > (map->getWidth()-1) || editWidth < 0);

//				do {
//					std::cout << std::endl << "Enter the vertical index of the cell you wish to edit: ";
//					std::cin >> editHeight;
//					// Make sure the index is valid
//					if (editHeight > (map->getHeight()-1) || editHeight < 0)
//						std::cout << "Invalid height! Please try again." << std::endl;
//				}
//				while (editHeight > (map->getHeight()-1) || editHeight < 0);

//				std::cout << std::endl << std::endl;

//				// Run setCell method
//				checkValid = map->setCell(editWidth, editHeight, editChar);
//			}
//		}
//	}
//}
//void loadMap()
//{
//	map = Grid::loadMap(player->level);
//	if (map == NULL)
//	{
//		puts("Could not load, returning to main menu...");
//	}
//	else
//	{
//		mapLoaded = true;
//	}
//}
