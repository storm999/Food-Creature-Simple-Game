#pragma once
#include "Console.h"
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
class Input
{
private:
	int numberOfFood;
	int numberOfCreature;
	int eatDistance;
	int amountOfDecreaseInHitpoint;
	int newOrExit;
	void readNumberOfFood();
	void readNumberOfCreatures();
	void readEatDistance();
	void readAmountOfDecreaseInHitpoint();
public:
	Input();
	~Input();
	int getNumberOfCreature();
	int getNumberOfFood();
	int getEatDistance();
	int getAmountOfDecreaseInHitpoint();
	void readAll(Console);
	void newGame(Console);
	int getNewGameOrExit();
};

