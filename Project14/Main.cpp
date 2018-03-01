#include <iostream>
#include <string>
#include <stdexcept>
#include <windows.h>
#include "Console.h"
#include "RandomNumber.h"
#include "Creature.h"
#include "Food.h"
#include "Board.h"
#include "Input.h"
#include <vector>
#include <algorithm>
#include "Statistics.h"

using namespace std;

int main()
{
	int newGameOrExit;
	do
	{
		Console console(70, 70);													//Creating an object from Console class
		console.setColour(console.COLOUR::BLACK, console.COLOUR::LIGHT_AQUA);		//It sets color of console to black and aqua
	
		Input read;																	//Creating an object from input class
		read.readAll(console);														//It reads all variable from user such as numbers of foods and creatures

		Board board(read.getNumberOfCreature(),read.getNumberOfFood(),console);		//Here we generate an object from board class
		board.newBoard(read.getNumberOfFood(), console, read);						//Almost everything about game like generating foods, creatures, fighting, eating happens here.
		board.localStats.printAllStats(console);									//This function prints statistics of game
		
		read.newGame(console);														//This function asks to user either he wants to replay or exit
		newGameOrExit=read.getNewGameOrExit();										//This function gets user’s decision
	}while (newGameOrExit == 1);													//Game restarts if user's inoput is 1
	return 0;
}
