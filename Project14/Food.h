#pragma once
using namespace std;

class Food
{
private:
	int X;
	int Y;
	int id;
	int foodSize;
	char foodPattern;	//I prefered to hold pattern of food here in case it might be wanted to change just for some spesific foods
public:
	Food() = default;
	Food(int, int, int);
	~Food();
	void sendFoodOutOfBoard();
	int getX();
	int getY();
	void setFoodSize(int);
	int getFoodSize();
	int getId();
	char getFoodPattern();
	void setId(int);
};
