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
	cout << "Score: " << score << endl;
}

void input()
{
	int check = 0;
	switch (check = _getch())
	{
	case PRESS_LEFT:
		pointerX--;
		break;
	case PRESS_RIGHT:
		pointerX++;
		break;
	case PRESS_UP:
		pointerY--;
		break;
	case PRESS_DOWN:
		pointerY++;
		break;
	}
}


int main()
{
	isGameOver = false;
	while (!isGameOver)
	{
		draw();
		input();
	}
	system("pause");
}
