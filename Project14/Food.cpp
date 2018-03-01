#include "Food.h"

Food::Food(int inX, int inY, int inId)
{
	X = inX;
	Y = inY;
	id = inId;
	foodSize = 3;
	foodPattern = '#';
}

Food::~Food()
{
}

int Food::getX()
{
	return X;
}

int Food::getY()
{
	return Y;
}

char Food::getFoodPattern()
{
	return foodPattern;
}

void Food::setFoodSize(int inFoodSize)
{
	foodSize = inFoodSize;
}

int Food::getFoodSize()
{
	return foodSize;
}

int Food::getId()
{
	return id;
}

void Food::setId(int inId)
{
	id = inId;
}

void Food::sendFoodOutOfBoard()	
{
	X = 100;
	Y = 100;
}