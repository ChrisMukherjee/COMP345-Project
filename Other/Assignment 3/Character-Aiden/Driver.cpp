#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <conio.h>

#include "Fighter.h"
#include "CharacterObserver.h"
#include "FighterDirector.h"
#include "BullyFighterBuilder.h"
#include "NimbleFighterBuilder.h"
#include "TankFighterBuilder.h"

int main()
{
	//////////////////////////////////////////////////////////////////////////
	// This part of the driver is to show the Builder Design Pattern
	// implementation for Fighter. It will generate three different Fighters,
	// each with their own specialized ability scores, in order of preference:
	//
	// Bully: Strength, Constitution, Dexterity, Intelligence, Charisma, Wisdom
	// Nimble: Dexterity, Constitution, Strength, Intelligence, Charisma, Wisdom 
	// Tank: Constitution, Dexterity, Strength, Intelligence, Charisma, Wisdom
	//////////////////////////////////////////////////////////////////////////

	srand(static_cast<unsigned int>(time(NULL)));
	FighterBuilder* bullyBuilder = new BullyFighterBuilder;
	FighterBuilder* nimbleBuilder = new NimbleFighterBuilder;
	FighterBuilder* tankBuilder = new TankFighterBuilder;

	FighterDirector director;

	director.setFighterBuilder(bullyBuilder);
	director.constructFighter();
	Fighter* bully = director.getFighter();
	bully->name = "Bully Fighter";

	director.setFighterBuilder(nimbleBuilder);
	director.constructFighter();
	Fighter* nimble = director.getFighter();
	nimble->name = "Nimble Fighter";

	director.setFighterBuilder(tankBuilder);
	director.constructFighter();
	Fighter* tank = director.getFighter();
	tank->name = "Tank Fighter";

	std::cout << bully->attributesToString() << "\n\n";
	std::cout << nimble->attributesToString() << "\n\n";
	std::cout << tank->attributesToString() << "\n\n";

	std::cout << "*************************** BEFORE LEVEL UP\n\n";
	//////////////////////////////////////////////////////////////////////////
	// This part of the driver is to show the level dependent characteristics
	// of a fighter, namely the fact that upon leveling up, the health,
	// attack bonus and number of attacks per round increases.
	//////////////////////////////////////////////////////////////////////////

	Fighter f("Buddy", 15);
	puts(f.characterSheetToString().c_str());
	std::cout << "*************************** AFETR LEVEL UP\n\n";
	f.levelUp();
	puts(f.characterSheetToString().c_str());

	_getch();

	return 0;
}