#pragma once
#include "map.h"

class Player
{
private:
	int money;
	int id;
	int location;
public:
	static Map map[24];
	void move(int);
	int rollDice();
	void buy();
	void punish();
	int getId();
	int getMoney();
	void setMoney(int);
	int getLocation();
	void setlocation(int);
	void addMoney(int);
	Player();

};


