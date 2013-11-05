//Steven Di Lullo
//9597662
//Comp 345 - Ind. Ass 2 
//Part 2 - D&D Map Constructor (with Observer)

#include "Grid.h"
#include <iostream>
#include <stdlib.h>
#include "GridObserver.h"
#include "InputManager.h"
#include "Windows.h"
#include "Fighter.h"
#include "CharacterObserver.h"


using namespace std;

int main()
{
	int width;
	int height;
	char yesOrNo;
	Fighter* f = new Fighter("Buddy", 1);
	CharacterObserver co(*f);
	std:: string move;
	
	cout<<"---------DUNGEONS & DRAGONS------------\n"
		<<"--------------MAP CREATOR--------------\n\n\n";


		//*************Promting the user for the map dimensions*****************************
		cout<<"**************STEP 1*******************\n";
		cout<<"Please enter the Width of the map: ";
		cin>>width;

		cout<<"Please enter the Height of the map: ";
		cin>>height;
		cout<<"\n\n";

		 Grid map = Grid(height,width);

		cout<<"\nRemeber that,\n\n" 
			<<"\t-The vertical indices start at 0 increasing from top to bottom\n"
			<<"\t-The horizontal indices start at 0 increasing from left to right\n"
			<<"\nAlso,\n\n"
			<<"\t 'S' -> start   'E' -> Exit\n" 
			<<"\t '#' -> Wall    '!' -> Occupied\n"  
			<<"\t '@' -> Player  '-' -> Free\n";
		//**********************************************************************************





		//****************The user places the start & exit points***************************
		cout<<"\n\n\n**************STEP 2*******************\n";
		cout<<"-Would you like to place the START tile? (Y/N) ";
		cin>>yesOrNo;
	
		if(yesOrNo=='Y' || yesOrNo=='y')
			map.setStart();
		

		cout<<"\n\n-Would you like to place the EXIT tile? (Y/N) ";
		cin>>yesOrNo;
		
		if(yesOrNo=='y' || yesOrNo=='Y')
		map.setEnd();
		//**********************************************************************************



		//********In this step the user places all necessary walls & occupied tiles*********
		cout<<"\n\n**************STEP 3*******************\n";
	
		//WALLS!
		cout<<"-Would you like to add some WALLS? (Y/N) ";
		cin>>yesOrNo;
	
		if(yesOrNo == 'Y' || yesOrNo == 'y')
		{
			do{

				map.setWalls();
				cout<<map.output()<<endl;

				cout<<"\nDo you want to add more WALLS? (Y/N) ";
				cin>>yesOrNo;
	
			}while(yesOrNo=='Y' || yesOrNo=='y');
		}

		//OCCUPIED!
		//cout<<"\n\n-Would you like to add some OCCUPIED cells? (Y/N)";
		//cin>>yesOrNo;

		//if(yesOrNo == 'Y' || yesOrNo == 'y')
		//{
		//	do{

		//		map.setOccu();
		//		cout<<map.output()<<endl;

		//		cout<<"\nDo you want to add more OCCUPIED tiles? (Y/N) ";
		//		cin>>yesOrNo;
	
		//	}while(yesOrNo=='Y' || yesOrNo=='y');
		//}
		//**********************************************************************************
	
		
		if( map.isValid())
		{
			cout << "Congratulations, your map is valid.\n"
				 
				 << "Remeber,\n"
				 << " - Use the ARROW kEYS to move around,\n"
				 << " - Use the ESCAPE KEY when you want to exit\n" 
				 << "Enjoy your game!\n";
			
			map.startGame(f);	
			cout<<map.output()<<"\n";
		}
		else
		{
			cout<<"\n\nUnfortunatley the map you have designed is not valid,\n";
				exit(EXIT_FAILURE);
		}



		//Declare grid oberserver
		GridObserver obs(&map);

		std:: vector <InputEvent> events;
		events.push_back(InputEvent("up",VK_UP));
		events.push_back(InputEvent("down",VK_DOWN));
		events.push_back(InputEvent("left",VK_LEFT));
		events.push_back(InputEvent("right",VK_RIGHT));
		events.push_back(InputEvent("character",0x43));


		events.push_back(InputEvent("quit",VK_ESCAPE));


		//loops allowing for user to move player around the map
		//each move calls notify() and thus updating the map
		do
		{
			cout<< "your turn! \n";
			move = InputManager :: getInput(events);
			if (move == "character")
			{
				f->notify();
			}
			else
			{
				map.move(move);
			}
		}while( move != "quit");
	
	

	cin.get();
	cin.get();
	return 0;

}