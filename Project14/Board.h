#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <windows.h>
#include "Console.h"
#include "RandomNumber.h"
#include "Creature.h"
#include "Food.h"
#include <vector>
#include <algorithm>
#include "Input.h"
#include "Statistics.h"

class Board
{
private:
	vector<Creature> creatures;
	vector<Creature> killList;
	vector<Food> foods;
	RandomNumber random;
	void generateFoods(int, Console);
	void printCreatures(Console);
	void killCreature(int);
public:
	Board(int, int, Console);
	~Board();
	Statistics localStats;
	void generateCreatures(int);
	void newBoard(int, Console, Input);
	int calculateDistance(Creature, Food);
	void findNearestFood(Input);
	bool locationCheck(Creature, Food);
	void Fight(Input);
	void eatNearestfood();
	void decreaseAllHitpoints(Input);
	void setAllNearestFoodIdAndDistanceToDefault();
	void killCreaturesInList();
	bool ifNotInKillListPush(Creature&);
	void setSuperCreatureif2CreaturesGeneratedtoSameLocation();
	void setIdToDefaultIfNotClosest();
};

