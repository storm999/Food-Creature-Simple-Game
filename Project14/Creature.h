#pragma once
#include "Food.h"

using namespace std;

class Creature
{
private:
	int id;
	int X;
	int Y;
	int hitpoint;
	int attack;					//Attack point is generated randomly and used for food fight
	int nearestFoodDistance;	
	Food nearestFood;			
	bool isSuperCreature;		//Set to true if its super creature, otherwise its false
public:
	Creature() = default;
	Creature(int, int, int, int);
	~Creature();
	int getX();
	int getY();
	int getId();
	void changeHitpoint(int);
	int getHitpoint();
	int getAttack();
	int getNearestFoodId();
	void setNearestFoodIdToDefault();
	int getNearestFoodDistance();
	void setNearestFoodDistance(int);
	Food getNearestFood();
	void setNearestFood(Food);
	bool getIsSuperCreature();
	void setSuperCreature();
};
