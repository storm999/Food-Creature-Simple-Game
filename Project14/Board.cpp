#include "Board.h"

Board::Board(int numberOfCreature, int numberOfFood, Console console)
{
	console.setConsoleSize(30, 31);
	console.setColour(console.COLOUR::BLACK, console.COLOUR::LIGHT_AQUA);
	creatures.reserve(numberOfCreature);
	foods.reserve(numberOfFood);
	random.initialiseSeed();
}

Board::~Board()
{
}

void Board::newBoard(int numberOfFoods, Console console,Input read)
{
	generateCreatures(read.getNumberOfCreature());			//Generates creatures, pushes them to the vector
	setSuperCreatureif2CreaturesGeneratedtoSameLocation();	//If 2 creatures are generated to same location, one disappear other one becomes superCreature
	killCreaturesInList();									//Deletes creatures from 'creatures' vector where they are also inserted into killList by previous functions
	while (creatures.size() > 0)							//Game runs as long as size of creatures vector isnt zero or less
	{
		setAllNearestFoodIdAndDistanceToDefault();			//For correct eating and fighting, 'nearestFood' object that every creatures has, has default id (-1) and default distance (100)
		printCreatures(console);							//Prints creatures to screen that they were already generated
		generateFoods(numberOfFoods, console);				//Generates foods and super foods, prints them to screen and checks if a food is dropped on a creature, if yes inserts creature to killList
		killCreaturesInList();								//Deletes creatures from 'creatures' vector where they are also inserted into killList by previous functions
		findNearestFood(read);								//Sets the neareast food to all creatures (if there is any in max eat distance)
		Fight(read);										//If distance of multiple creatures to the same food is equal to each other, they all fight, only one survives and eats
		killCreaturesInList();								//Deletes creatures from 'creatures' vector where they are also inserted into killList by previous functions			
		setIdToDefaultIfNotClosest();						//If same food is set to multiple creatures as nearest food, far away ones' nearestFoodId will be set to default (-1), so only closesnt one will be able to eat that food (the ones that their distances to same food were equal to each other already fought )
		eatNearestfood();									//Finally creautres that have nearest food, eat their foods and gain hitpoint
		decreaseAllHitpoints(read);							//Decrease hitpoint of all creatures every round by the amount the user chooses
		killCreaturesInList();								//Deletes creatures from 'creatures' vector where they are also inserted into killList by previous functions
		localStats.incRoundNumber();						//Increases round number of statistics by 1
		console.clear();									//Cleans console for next round
	}
}

void Board::generateCreatures(int numberOfCreature)		//Generates Creatures
{
	for (int i = 0; i < numberOfCreature; i++)		
	{
		creatures.push_back(Creature(random.random(0, 29), random.random(0, 29), random.random(0, 20), i));
	}

}

void Board::setSuperCreatureif2CreaturesGeneratedtoSameLocation()	//If 2 creatures are generated to same location, 
{																	//One disappear other one becomes superCreature
	if (creatures.size() >= 2)
	{
		for (int i = 0; i < creatures.size() - 1; i++)
		{
			for (int j = i + 1; j < creatures.size(); j++)
			{
				if (creatures[i].getX() == creatures[j].getX() && creatures[i].getY() == creatures[j].getY())
				{
					creatures[j].setSuperCreature();
					killList.push_back(creatures[i]);
				}
			}
		}
	}
}

void Board::printCreatures(Console console)
{
	for (int i = 0; i < creatures.size(); i++)		//Prints Creatures
	{
		console.gotoXY(creatures[i].getX(), creatures[i].getY());
		if (creatures[i].getIsSuperCreature())			// If creature is superCreature, it will be printed as yellow
		{
			console.setColour(console.COLOUR::BLACK, console.COLOUR::LIGHT_YELLOW);
			cout << creatures[i].getHitpoint();
			console.setColour(console.COLOUR::BLACK, console.COLOUR::LIGHT_AQUA);
		}
		else
		{
			cout << creatures[i].getHitpoint();			//Printing normal creature as default color
		}	
	}
	console.gotoXY(29, 29);
	getchar();
}

void Board::generateFoods(int numberOfFood, Console console)
{
	foods.clear();								//Each round a cleen food list is needed
	int tempDied=0;
	for (int i = 0; i < numberOfFood; i++)		//Generating foods
	{
		foods.push_back(Food(random.random(0, 29), random.random(0, 29), i));
		console.gotoXY(foods[i].getX(), foods[i].getY());
		cout << foods[i].getFoodPattern();				//Prints food pattern

		for (int j = 0; j < creatures.size(); j++)		//Kills creatures when food drop on them
		{
			if (locationCheck(creatures[j], foods[i]))
			{	
				killList.push_back(creatures[j]);
				tempDied++;								//SetCreaturesDiedbyFoodDrop function isnt called here to in order to increase cpu efficency
			}
		}
	}
	localStats.setCreaturesDiedbyFoodDrop(tempDied);

	for (int i = 0; i < foods.size()-1; i++)
	{
		for (int j = i + 1; j < foods.size(); j++)
		{
			if (foods[i].getX() == foods[j].getX() && foods[i].getY() == foods[j].getY())	//Create super food
			{
				foods[j].setFoodSize(6);			//Sets hitpoint of super food to 5 (1 will be decreased by other function)
				foods[i].sendFoodOutOfBoard();		//Preferd to send it out of board rather than deleting. Deleting causes program work instabil and a stabil algorithm requires too much cpu
				console.gotoXY(foods[j].getX(), foods[j].getY());
				console.setColour(console.COLOUR::BLACK, console.COLOUR::LIGHT_GREEN);	//Super food is printed in different color
				cout << foods[j].getFoodPattern();
				console.setColour(console.COLOUR::BLACK, console.COLOUR::LIGHT_AQUA);	//Sets color to default
			}
		}
	}
	console.gotoXY(29, 29);
	getchar();
}

void Board::killCreature(int j)
{
	creatures.erase(creatures.begin() + j);
}

void Board::killCreaturesInList()
{
	for (int i = 0; i < creatures.size(); i++)
	{
		if (i >= creatures.size())			//Avoids exception
			break;
		for (int j = 0; j < killList.size(); j++)
		{
			if (killList[j].getId() == creatures[i].getId())
			{
				killCreature(i);
				if (i >= creatures.size())		//Avoids exception
					break;
			}
		}
	}
	killList.clear();						//Clears kill list for next round
}

bool Board::locationCheck(Creature creature, Food food)		// Returns true if location of food and creature are same
{
	if (creature.getX() == food.getX() && creature.getY() == food.getY())
	{
		return true;
	}
	else
		return false;
}

int Board::calculateDistance(Creature creature, Food food)	//Returns distance between creature and food
{
	int x = food.getX() - creature.getX();
	int y = food.getY() - creature.getY();
	int distance = sqrt(x*x + y*y);
	return distance;
}

void Board::eatNearestfood()
{
	for (int i = 0; i < creatures.size(); i++)
	{
		if (creatures[i].getNearestFoodId() != -1)
		{
			localStats.incHowManyFoodsEaten();
			creatures[i].changeHitpoint(creatures[i].getNearestFood().getFoodSize());
		}
	}
}


void Board::findNearestFood(Input read)
{
	int minDistance = 100;
	int distance;

	for (int i = 0; i < creatures.size(); i++)
	{
		for (int j = 0; j < foods.size(); j++)
		{
			distance = calculateDistance(creatures[i],foods[j]);

			if (distance < minDistance && distance <= read.getEatDistance())
			{
				minDistance = distance;
				creatures[i].setNearestFood(foods[j]);
				creatures[i].setNearestFoodDistance(minDistance);
			}
		}
		minDistance = 100;
	}
}

bool Board::ifNotInKillListPush(Creature &creature)		//Checks if sent creatures is already in killList or not
{
	bool exist=false;
	for (int i = 0; i < killList.size(); i++)
	{
		if (creature.getId() == killList[i].getId())
		{
			exist = true;
			return false;
		}
	}
	return true;
}

void Board::Fight(Input read)
{
	if (creatures.size() >= 2)				//Avoids exception
	{
		for (int i = 0; i < creatures.size()-1; i++)
		{
			for (int j = i+1; j < creatures.size(); j++)
			{
				if (creatures[i].getNearestFoodId() == creatures[j].getNearestFoodId() &&
					creatures[i].getNearestFoodDistance() == creatures[j].getNearestFoodDistance() &&
					creatures[i].getId() != creatures[j].getId() &&
					creatures[i].getNearestFoodId() != -1)
				{
					if (creatures[i].getAttack() < creatures[j].getAttack())		//The one which its attack value is smaller dies
					{
						if(ifNotInKillListPush(creatures[i]))
						{
							killList.push_back(creatures[i]);
							localStats.incNumberOfCreaturesDiedInFight();
						}
							
					}
					else            //Else other one dies (if their attack values are equal to each other the one with index J dies)
					{
						if (ifNotInKillListPush(creatures[j]))
						{
							killList.push_back(creatures[j]);
							localStats.incNumberOfCreaturesDiedInFight();
						}
					}
				}
			}
		}
	}
}

void Board::decreaseAllHitpoints(Input read)		//Decrease hitpoint of all creatures every round
{
	for (int i = 0; i < creatures.size(); i++)
	{
		creatures[i].changeHitpoint(-(read.getAmountOfDecreaseInHitpoint()));	//Decrease amount is got from user
		if (creatures[i].getHitpoint() <= 0)
		{
			if(ifNotInKillListPush(creatures[i]))
				killList.push_back(creatures[i]);
		}
	}
}

void Board::setAllNearestFoodIdAndDistanceToDefault()
{
	for (int i = 0; i < creatures.size(); i++)
	{
		creatures[i].setNearestFoodIdToDefault();
		creatures[i].setNearestFoodDistance(100);
	}
}

void Board::setIdToDefaultIfNotClosest()	
{
	if (creatures.size() >= 2)
	{
		for (int i = 0; i < creatures.size() - 1; i++)
		{
			for (int j = i + 1; j < creatures.size(); j++)
			{
				if (creatures[i].getNearestFoodId() == creatures[j].getNearestFoodId())
				{
					if (creatures[i].getNearestFoodDistance() < creatures[j].getNearestFoodDistance())
					{
						creatures[j].setNearestFoodIdToDefault();
					}
					else
					{
						creatures[i].setNearestFoodIdToDefault();
					}
				}
			}
		}
	}
}