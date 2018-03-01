#pragma once
#include "Console.h"

class Statistics
{
private:
	int roundNumber;
	int creaturesDiedbyFoodDrop;
	int howManyFoodsEaten;
	int numberOfCreaturesDiedInFight;
public:
	int getNumberOfCreaturesDiedInFight();
	Statistics();
	~Statistics();
	void incRoundNumber();
	int getRoundNumber();
	void setCreaturesDiedbyFoodDrop(int);
	int getCreaturesDiedbyFoodDrop();
	void incHowManyFoodsEaten();
	int getHowManyFoodsEaten();
	void printAllStats(Console);
	void incNumberOfCreaturesDiedInFight();
};

