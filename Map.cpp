#include "Map.h"
#include<iostream>
using namespace std;

int Map::getFine() {
	return fine;
}
int Map::getPrice() {
	return price;
}
int Map::getOwner() {
	return owner;
}
void Map::setOwner(int o) {
	owner = o;
}
Map::Map() {
	price = 100;
	owner = 5;
	fine = 200;
}
