#include "Creature.h"


Creature::Creature(int inX, int inY, int inAttack, int inId)
{
	X = inX;
	Y = inY;
	id = inId;
	attack = inAttack;
	hitpoint = 5;
	nearestFoodDistance = 100;
	isSuperCreature = false;
}

Creature::~Creature()
{
}

int Creature::getId()
{
	return id;
}

int Creature::getX()
{
	return X;
}

int Creature::getY()
{
	return Y;
}

int Creature::getHitpoint()
{
	return hitpoint;
}

void Creature::changeHitpoint(int inHitpoint)
{
	if (hitpoint + inHitpoint >= 10)
	{
		hitpoint = 10;
	}
	else
	{
		hitpoint += inHitpoint;
	}
}

int Creature::getAttack()
{
	return attack;
}

int Creature::getNearestFoodDistance()
{
	return nearestFoodDistance;
}

int Creature::getNearestFoodId()
{
	return nearestFood.getId();
}

void Creature::setNearestFoodIdToDefault()
{
	nearestFood.setId(-1);
}

void Creature::setNearestFoodDistance(int inDistance)
{
	nearestFoodDistance = inDistance;
}

Food Creature::getNearestFood()
{
	return nearestFood;
}

void Creature::setNearestFood(Food inFood)
{
	nearestFood = inFood;
}

bool Creature::getIsSuperCreature()
{
	return isSuperCreature;
}

void Creature::setSuperCreature()
{
	isSuperCreature = true;
	hitpoint = 9;
	attack = 25;
}

