//Steven Di Lullo
//9597662
//Comp 345 - Ind. Ass 2 
//Part 2 - D&D Map Constructor (with Observer)

#include "Grid.h"
#include <iostream>
#include <stdlib.h>
#include "GridObserver.h"

using namespace std;

int main()
{
	int width;
	int height;
	char move,yesOrNo;
	
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

		cout<<"Here is the deafult map... \n";

		map.output();

		cout<<"\nRemeber that,\n\n" 
			<<"\t-The vertical indices start at 0 increasing from top to bottom\n"
			<<"\t-The horizontal indices start at 0 increasing from left to right\n"
			<<"\nAlso,\n\n"
			<<"\t 'S' -> start   'E' -> Exit\n" 
			<<"\t '#' -> Wall    '!' -> Occupied\n"  
			<<"\t '-' -> Free\n";
		//**********************************************************************************





		//****************The user places the start & exit points***************************
		cout<<"\n\n\n**************STEP 2*******************\n";
		cout<<"-Would you like to move the START tile? (Y/N) ";
		cin>>yesOrNo;
	
		if(yesOrNo=='Y' || yesOrNo=='y')
			map.setStart();
		

		cout<<"\n\n-Would you like to move the EXIT tile? (Y/N) ";
		cin>>yesOrNo;
		
		if(yesOrNo=='y' || yesOrNo=='Y')
		map.setEnd();
		//**********************************************************************************
	
	



		cout<<"Here is the map so far...\n";
		map.output();




		//********In this step the user places all necessary walls & occupied tiles*********
		cout<<"\n\n**************STEP 3*******************\n";
	
		//WALLS!
		cout<<"-Would you like to add some WALLS? (Y/N) ";
		cin>>yesOrNo;
	
		if(yesOrNo == 'Y' || yesOrNo == 'y')
		{
			do{

				map.setWalls();
				map.output();

				cout<<"\nDo you want to add more WALLS? (Y/N) ";
				cin>>yesOrNo;
	
			}while(yesOrNo=='Y' || yesOrNo=='y');
		}

		//OCCUPIED!
		cout<<"\n\n-Would you like to add some OCCUPIED cells? (Y/N)";
		cin>>yesOrNo;

		if(yesOrNo == 'Y' || yesOrNo == 'y')
		{
			do{

				map.setOccu();
				map.output();

				cout<<"\nDo you want to add more OCCUPIED tiles? (Y/N) ";
				cin>>yesOrNo;
	
			}while(yesOrNo=='Y' || yesOrNo=='y');
		}
		//**********************************************************************************
	
		
		if( map.isValid())
		{
			cout << "Congratulations, your map is valid.\nEnjoy your game!";
			map.startGame();			
		}
		else
		{
			cout<<"\n\nUnfortunatley the map you have designed is not valid,\n";
				exit(EXIT_FAILURE);
		}

		GridObserver obs(&map);

		do
		{
			cout<< "your turn! ";
			cin>> move;
			map.move(move);
		}while( move=='w' || move=='d' || move=='s' || move=='a');
	
	

	cin.get();
	cin.get();
	return 0;

}