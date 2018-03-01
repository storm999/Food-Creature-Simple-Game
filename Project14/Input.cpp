#include "Input.h"
#include <iostream>

Input::Input()
{
}

Input::~Input()
{
}

void Input::readAll(Console console)
{
	readNumberOfFood();
	readNumberOfCreatures();
	readEatDistance();
	readAmountOfDecreaseInHitpoint();
	console.clear();
}

void Input::readNumberOfFood()
{
	std::cout << "Enter number of food: between 0 and 500: ";
	std::cin >> numberOfFood;
	while (numberOfFood > 500 || numberOfFood < 0)
	{
		std::cout << "Invalid input please enter between 0 and 500: ";
		std::cin >> numberOfFood;
	}
}

void Input::readNumberOfCreatures()
{
	std::cout << "Enter number of creatures between 0 and 500: ";
	std::cin >> numberOfCreature;
	while (numberOfCreature > 500 || numberOfCreature < 0)
	{
		std::cout << "Invalid input please enter between 0 and 500: ";
		std::cin >> numberOfCreature;
	}
}

void Input::readEatDistance()
{
	std::cout << "Enter max eat distance between 0 and 10: ";
	std::cin >> eatDistance;
	while (eatDistance > 10 || eatDistance < 0)
	{
		std::cout << "Invalid input please enter between 0 and 10: ";
		std::cin >> eatDistance;
	}
}

void Input::readAmountOfDecreaseInHitpoint()
{
	std::cout << "How much hit point should be decreased from each creature" << std::endl << "every round between 0 and 4: ";
	std::cin >> amountOfDecreaseInHitpoint;
	while (amountOfDecreaseInHitpoint > 4 || amountOfDecreaseInHitpoint < 0)
	{
		std::cout << "Invalid input please enter between 0 and 4: ";
		std::cin >> amountOfDecreaseInHitpoint;
	}
}

void Input::newGame(Console console)
{
	std::cout << "Please enter 1 to restart game or 2 to exit: ";
	std::cin >> newOrExit;
	while (newOrExit != 1 && newOrExit != 2)
	{
		std::cout << "Invalid input please enter 1 or 2: ";
		std::cin >> newOrExit;
	}
	console.clear();
}

int Input::getNewGameOrExit()
{
	return newOrExit;
}

int Input::getAmountOfDecreaseInHitpoint()
{
	return amountOfDecreaseInHitpoint;
}

int Input::getNumberOfCreature()
{
	return numberOfCreature;
}

int Input::getNumberOfFood()
{
	return numberOfFood;
}

int Input::getEatDistance()
{
	return eatDistance;
}