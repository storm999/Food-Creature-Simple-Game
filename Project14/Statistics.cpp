#include "Statistics.h"


Statistics::Statistics()
{
	roundNumber = 0;
	creaturesDiedbyFoodDrop = 0;
	howManyFoodsEaten = 0;
	numberOfCreaturesDiedInFight=0;
}

Statistics::~Statistics()
{
}

void Statistics::printAllStats(Console console)
{
	console.setConsoleSize(70, 70);
	console.setColour(console.COLOUR::BLUE, console.COLOUR::WHITE);
	std::cout << "Statistics of Game" << std::endl << std::endl;
	std::cout << "Total round number: " << getRoundNumber() << std::endl;
	std::cout << "Total number of creatures that killed by food drop: " << getCreaturesDiedbyFoodDrop() << std::endl;
	std::cout << "Total number of foods eaten by creatures: " << getHowManyFoodsEaten() << std::endl;
	std::cout << "Total number of creatures that died in food fight: " << getNumberOfCreaturesDiedInFight() << std::endl << std::endl;
}

int Statistics::getRoundNumber()
{
	return roundNumber;
}

void Statistics::incRoundNumber()
{
	roundNumber++;
}

int Statistics::getCreaturesDiedbyFoodDrop()
{
	return creaturesDiedbyFoodDrop;
}

void Statistics::setCreaturesDiedbyFoodDrop(int inCreaturesDiedbyFoodDrop)
{
	creaturesDiedbyFoodDrop += inCreaturesDiedbyFoodDrop;
}

int Statistics::getHowManyFoodsEaten()
{
	return howManyFoodsEaten;
}

void Statistics::incHowManyFoodsEaten()
{
	howManyFoodsEaten++;
}

void Statistics::incNumberOfCreaturesDiedInFight()
{
	numberOfCreaturesDiedInFight++;
}

int Statistics::getNumberOfCreaturesDiedInFight()
{
	return numberOfCreaturesDiedInFight;
}