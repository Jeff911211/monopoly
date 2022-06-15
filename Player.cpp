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
		cout << "�A�}���F" << endl;
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
	cout << "�O�_��" << map[location].getPrice() << "���ʶR��" << location << "���a";
	char r;
	cout << "�п�J1�ʶR(��J0���ʶR):";
	cin >> r;
	while (r != 49 && r != 48) {
		cout << "�п�J1�ʶR(��J0���ʶR):";
		cin >> r;
	}
	if (r == 49) {
		if (money >= map[location].getPrice()) {
			money = money - map[location].getPrice();
			map[location].setOwner(id);
			cout << "�ʶR���\" << endl;
		}
		else
			cout << "�������A�ʶR����" << endl;
	}
}

void Player::punish() 
{
	money = money - map[location].getFine();
	cout << "�A�Q�@�F" << map[location].getFine() << "���A�A�{�b��" << money << "��" << endl;

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