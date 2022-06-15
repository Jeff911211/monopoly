#pragma once


class Map
{
private:
	int price;
	int owner;
	int fine;

public:
	int getPrice();
	int getOwner();
	int getFine();
	void setOwner(int);
	Map();

};

