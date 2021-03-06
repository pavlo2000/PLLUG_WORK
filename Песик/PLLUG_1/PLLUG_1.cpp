// PLLUG_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <random>
#include <ctime>

using namespace std;
const char mapCodeUser = '@';
const char mapCodeExit = 'E';
const char mapCodeWall = 'X';
const char mapCodeField = ' ';
const int mapColums = 20;
const int mapRows = 20;
using Map = array<array<char, mapRows>, mapColums>;
array<array<char, mapRows>,mapColums> map;

bool doesUserWantToPlay();
void display();
void field();
void StartUserAndExitPos();
void UserMove();
bool ChekMoveAcsses(char MoveWay);
void GameLevelCheker();
void LevelOptions(int GameLevel);


int ExitPosX, ExitPosY, UserPosX, UserPosY;
int main()
{
	Map map;	
	while (doesUserWantToPlay())
	{
		field();
		display();
		while ((UserPosX != ExitPosX || UserPosY != ExitPosY))
		{
			UserMove();
		}
		cout << "U WIN" << endl;                                     
	}
}

bool doesUserWantToPlay()
{
	bool result = false;
	char answer = '\0';
	cout << "==Labirint==" << endl;
	while (true)
	{	
		cout << "Do you want to play game? ((1) - Yes | (0) -NO)" << endl;
		cin >> answer;
		if (answer == '1')
		{
			result = true;
			return result;
		}
		else if (answer == '0')
		{
			cout << "buy buy" << endl;
			break;
		}
		else
		{
			cout << "I don't understand u!" << endl;

		}
	}
	return result;
}
void display()
{
	for (int column = 0; column < mapColums; ++column)
	{
		for (int row = 0; row < mapRows; ++row)
		{
			cout << map[column][row];
		}
		cout << endl;
	}
}
void field()
{
	for (int column = 0; column < mapColums; ++column)
	{
		for (int row = 0; row < mapRows; ++row)
		{
			map[column][row] = mapCodeField;
		}
	}
	for (int column = 0; column < mapColums; column++)
	{
		map[mapColums-1][column] = mapCodeWall;
		map[0][column] = mapCodeWall;
		map[column][0] = mapCodeWall;
		map[column][mapRows-1] = mapCodeWall;
	}
	GameLevelCheker();
	StartUserAndExitPos();
}
void StartUserAndExitPos()
{
	time_t Forrandom;
	Forrandom = time(NULL);
	srand(Forrandom);
	ExitPosX = rand() % (mapColums-1)+1;
	ExitPosY = rand() % (mapRows-1)+1;
	UserPosX = rand() % (mapColums-1)+1;
	UserPosY = rand() % (mapRows-1)+1;
	if (ExitPosY == UserPosX && ExitPosX == UserPosX)
	{
		StartUserAndExitPos();
	}
	map[ExitPosX][ExitPosY] = mapCodeExit;
	map[UserPosX][UserPosY] = mapCodeUser;
}
void UserMove()
{
	char WayToMove;
	cout << "Please input way to move!((u) - up, (d) - down,(r) - right, (l) -left).(If u can't win or dislike to play please enter e" << endl;
	cin >> WayToMove;
	if (ChekMoveAcsses(WayToMove))
	{
		display();
	}
	else
	{
		cout << "U can't move there" << endl;
	}
	
	
}
bool ChekMoveAcsses(char MoveWay)
{
	int newUserPosX=UserPosX, newUserPosY=UserPosY;
	switch (MoveWay)
	{
	case 'u':
	{
		newUserPosX = UserPosX - 1;
		break;
	}
	case 'd':
	{
		newUserPosX = UserPosX + 1;
		break;
	}
	case 'r':
	{
		newUserPosY = UserPosY + 1;
		break;
	}
	case 'l':
	{
		newUserPosY = UserPosY - 1;
		break;
	}
	case 'e':
	{
		exit(0);
	}
	default:
		cout << "I don'y understand u!" << endl;
		return false;
	}
	if (map[newUserPosX][newUserPosY] != mapCodeWall)
	{
		map[UserPosX][UserPosY] = mapCodeField;
		UserPosX = newUserPosX;
		UserPosY = newUserPosY;
		map[UserPosX][UserPosY] = mapCodeUser;
		return true;
	}
	return false;
}

void GameLevelCheker()
{
	int LevelCheker,GameLevel;
	cout <<"Do u want select level?((1) - Yes, (0) - No)" << endl;
	cin >> LevelCheker;
	if (LevelCheker == 1)
	{
		cout << "Select level(input number of level)" << endl;
		cout << "0. Zero level(0 partitions)" << endl;
		cout << "1. First level(10 partitions)" << endl;
		cout << "2. Secknd Level(30 partitions)" << endl;
		cout << "3. Third level(60 partitions)" << endl;
		cin >> GameLevel;
		LevelOptions(GameLevel);
	}
}
void LevelOptions(int GameLevel)
{
	int NumberOfPartitions, PartitionsPosX, PartitionsPosY;
	switch (GameLevel)
	{
	case 0:
	{
		NumberOfPartitions = 0;
		break;
	}
	case 1:
	{
		NumberOfPartitions = 10;
		break;
	}
	case 2:
	{	NumberOfPartitions = 30;
	break;
	}
	case 3:
	{
		NumberOfPartitions = 60;
		break;
	}
	default:
		cout << "I don't understand u" << endl;
		GameLevelCheker();
		break;
	}

	srand(time(NULL));
	for (int Pos = 0; Pos < NumberOfPartitions; Pos++)
	{
		PartitionsPosX = rand() % (mapColums-1)+ 1;
		PartitionsPosY = rand() % (mapRows-1) + 1;
		map[PartitionsPosX][PartitionsPosY] = mapCodeWall;
	}
}
;

