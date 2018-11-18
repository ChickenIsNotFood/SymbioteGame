#include<iostream>
#include<conio.h>
#define PRESS_UP 72
#define PRESS_DOWN 80
#define PRESS_LEFT 75
#define PRESS_RIGHT 77
using namespace std;

const int coordinateX = 30;
const int coordinateY = 18;

int score;

bool isGameOver;

int i, j;

int pointerX = coordinateX / 2;
int pointerY = coordinateY / 2;

enum moving { UP, DOWN, LEFT, RIGHT, ENDGAME,STOP=0 };

moving pointer;


void draw()
{
	system("cls");
	for (i = 0; i <= coordinateX; i++) cout << "#";
	cout << endl;

	for (i = 0; i < coordinateY; i++)
	{
		for (j = 0; j <= coordinateX; j++)
		{
			if (j == 0) cout << "#";
			else if (j == pointerX && i == pointerY) cout << "@";
			else if (j == coordinateX) cout << "#";
			else cout << " ";
		}
		cout << endl;
	}

	for (i = 0; i <= coordinateX; i++) cout << "#";
	cout << endl;
	cout << "Score: " << score<<endl;

}

void input()
{
		int check = 0;
		switch (check = getch())
		{
		case PRESS_LEFT:
			pointer = LEFT;
			break;
		case PRESS_RIGHT:
			pointer = RIGHT;
			break;
		case PRESS_UP:
			pointer = UP;
			break;
		case PRESS_DOWN:
			pointer = DOWN;
			break;
		case'X':
		case'x':
			pointer = ENDGAME;
			break;
		}
}

void logic()
{
	switch (pointer)
	{
	case UP:
		pointerY--;
		break;
	case DOWN:
		pointerY++;
		break;
	case LEFT:
		pointerX--;
		break;
	case RIGHT:
		pointerX++;
		break;
	case ENDGAME:
		isGameOver = true;
		break;
	default:
		break;
	}

	if (pointerX == coordinateX)
	{
		if (pointerY == coordinateY || pointerY == 0)
		{
			isGameOver = true;
		}
	}
	else if (pointerY == coordinateY)
	{
		if (pointerX == coordinateX || pointerX == 0)
			isGameOver = true;
	}
}

int main()
{
	isGameOver = false;
	while (!isGameOver)
	{
		draw();
		input();
		logic();
	}
	system("pause");
}
