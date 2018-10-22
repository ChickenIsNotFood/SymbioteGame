//symbiote
#include<iostream>
#include <time.h>
#include <Windows.h>
#include "string"
#include "conio.h"

#define max 100

using namespace std;

const int chieuDai = 15;
const int chieuRong = 30;

int i, j, score;

bool isGameOver;

enum keyboard { stop = 0, up, down, left, right };

keyboard dir;

struct point
{
	int x;
	int y;
};

point symbiotes[max];
point fruit;

void setup()
{
	score = 0;
	isGameOver = false;
	dir = stop;
}

void draw()
{
	system("cls");
	//khung_tren
	for (i = 0; i < chieuRong; i++)
	{
		cout << "#";
	}
	//khung_trai_phai
	cout << endl;
	for (int i = 2; i < chieuDai; i++)
	{
		cout << "#";
		for (int j = 1; j < chieuRong - 1; j++)
		{
			cout << " ";
		}
		cout << "#" << endl;
	}
	//khung_duoi
	for (i = 0; i < chieuRong; i++)
	{
		cout << "#";
	}
	cout << endl;

}

void input()
{
	/*if (_kbhit())
	{
		switch (_getch())
		{
		case'w':
			dir = up;
			break;
		case'a':
			dir = left;
			break;
		case'd':
			dir = right;
			break;
		case's':
			dir = down;
			break;
		default:
			dir = stop;
			break;
		}
	}*/
}

void logic()
{

}


int main()
{
	draw();

	system("pause");
	return 0;
}
