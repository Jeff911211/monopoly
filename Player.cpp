#include "player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Map Player::map[24];
static int Id = 0;

int Player::getMoney() {
	if (money < 0)
	{
		cout << "你破產了" << endl;
		return 0;
	}
	return money;
}

void Player::setMoney(int money)
{
	this->money = money;
}

int Player::getLocation()
{
	return location;
}

void Player::setlocation(int location)
{
	this->location = location;
}

int Player::rollDice()
{
	return  (1 + rand() % 6);
}

void Player::move(int n) {
	location = (location + n) % 24;
}


void Player::buy() 
{
	cout << "是否花" << map[location].getPrice() << "元購買第" << location << "號地";
	char r;
	cout << "請輸入1購買(輸入0不購買):";
	cin >> r;
	while (r != 49 && r != 48) {
		cout << "請輸入1購買(輸入0不購買):";
		cin >> r;
	}
	if (r == 49) {
		if (money >= map[location].getPrice()) {
			money = money - map[location].getPrice();
			map[location].setOwner(id);
			cout << "購買成功" << endl;
		}
		else
			cout << "錢不夠，購買失敗" << endl;
	}
}

void Player::punish() 
{
	money = money - map[location].getFine();
	cout << "你被罰了" << map[location].getFine() << "元，你現在剩" << money << "元" << endl;

}

int Player::getId() 
{
	return id;
}

void Player::addMoney(int n)
{
	money += n;
}

Player::Player() {
	money = 3000;
	location = 0;
	id = Id;
	Id++;
}