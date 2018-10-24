// RPS Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include<istream>
#include<string>
#include<random>
#include<time.h>
using namespace std;


bool ResultOFGame(char UserVariant);
bool Result=false;
array  <char, 3> BotVariant = { 'R','S','P' };

int main()
{
	int VinTimes=0;
	char UserVariant;
	cout << "==Rock Paper and Scissos=="<<endl; 	
	cout <<"Input Rock(R) Parer(P) or Scissors(S)"<<endl;
	cin >> UserVariant;
	if (ResultOFGame(UserVariant))
	{
		cout<<"U VIN"<<endl;
	}
	else
	{
		cout << "Sorry u losse" << endl;
	}
}

bool ResultOFGame(char UserVariant)
{
	int BotChek;
	srand(time(NULL));
		BotChek = rand() % 3;
		switch (UserVariant)
		{
		case 'R':
		{
			if (BotVariant[BotChek] == 'S')
			{
				cout << BotVariant[BotChek] << endl;
				Result = true;
			}
			else if(BotVariant[BotChek] == 'P')
			{
				cout << BotVariant[BotChek] << endl;
				Result = false;
			}
			else
			{
				cout << BotVariant[BotChek] << endl;
				cout << "Draw" << endl;
				exit(0);
			}
			break;
		}
		case 'S': {
			if (BotVariant[BotChek] == 'P')
			{
				cout << BotVariant[BotChek] << endl;
				Result = true;
			}
			else if (BotVariant[BotChek] == 'R')
			{
				cout << BotVariant[BotChek] << endl;
				Result = false;
			}
			else
			{
				cout << BotVariant[BotChek] << endl;
				cout << "Draw" << endl;
				exit(0);
			}
			break;
		}
		case 'P':
		{
			if (BotVariant[BotChek] == 'R')
			{
				cout << BotVariant[BotChek] << endl;
				Result = true;
			}
			else if (BotVariant[BotChek] == 'S')
			{
				cout << BotVariant[BotChek] << endl;
				Result = false;
			}
			else

			{
				cout << BotVariant[BotChek] << endl;
				cout << "Draw" << endl;
				exit(0);
			}
			break;
		}
		default:
		{cout << "I don't understand u" << endl;
		exit(0);
		}
		}
	return Result;
}
