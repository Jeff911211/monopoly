#include "Player.h"
#include "Map.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void setGame(Player[], int);
void printStates(Player[], int);
void event(Player[], int);


int main()
{
    int playerNumber;
    char dice = '1';
    int i = 0, diceNum = 0;
    srand(time(0));


    cout << "請輸入遊玩人數(2~4 人): ";
    cin >> playerNumber;
    while (playerNumber > 4 or playerNumber < 2)
    {
        cout << "請正確輸入人數(2~4 人): ";
        cin >> playerNumber;
    }

    Player* user = new Player[playerNumber];

    setGame(user, playerNumber);
    printStates(user, playerNumber);

    while (dice != '0')
    {
        cout << "現在是 Player" << 1 + i % playerNumber << " 骰骰子" << endl;
        cout << "請輸入 Y 確認要骰骰子(或輸入 0 結束遊戲):";

    ERROR:
        cin >> dice;

        //判斷是否要骰骰子
        switch (dice)
        {
        default:
            cout << ">>>>>>>>>>>>>>>>>輸入錯誤<<<<<<<<<<<<<<<<<" << endl;
            cout << "請輸入 Y 確認要骰骰子(或輸入 0 結束遊戲):";
            goto ERROR;
        case '0':
            cout << " >> 準備結束遊戲 << " << endl;
            break;
        case 'y':
            diceNum = user[i % playerNumber].rollDice();
            cout << "骰到 " << diceNum << endl;
            user[i % playerNumber].move(diceNum);
            event(user, i % playerNumber);
            printStates(user, playerNumber);
            break;
        case 'Y':

            diceNum = user[i % playerNumber].rollDice();
            cout << "骰到 " << diceNum << endl;
            user[i % playerNumber].move(diceNum);
            event(user, i % playerNumber);
            printStates(user, playerNumber);
            break;
        }

        i++;
    }
}


//初始化各個玩家狀態
void setGame(Player array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        array[i].setMoney(3000);
        array[i].setlocation(0);
    }
}

//列印各個玩家狀態
void printStates(Player user[], int playerNumber)
{
    cout << "**************************************************" << endl;
    for (int i = 0; i < playerNumber; i++)
    {

        cout << "*  Player" << i + 1 << "'s money:" << left << setw(4) << user[i].getMoney()
            << " Player" << i + 1 << "'s location:" << left << setw(3) << user[i].getLocation() << "   *" << endl;
    }
    cout << "**************************************************" << endl;
}

//判斷到達這塊地會發生的事情
void event(Player user[], int id)
{
    if (user->map[user[id].getLocation()].getOwner() == 5)
        user[id].buy();
    else if (user->map[user[id].getLocation()].getOwner() != 5 && user->map[user[id].getLocation()].getOwner() != id)
    {
        user[id].punish();
        user[user->map[user[id].getLocation()].getOwner()].addMoney(user->map[user[id].getLocation()].getFine());
        cout << "player" << user->map[user[id].getLocation()].getOwner() + 1 << "得到了" << user->map[user[id].getLocation()].getFine() << "元" << endl;

    }
    else
        cout << "這是你的地" << endl;
}