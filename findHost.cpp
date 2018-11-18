#include<iostream>
#include<conio.h>
#include<Windows.h>

using namespace std;

const int coordinateX = 30;
const int coordinateY = 18;

int score;

bool isGameOver;

int i, j;

int nails = 1;

int pointerX = coordinateX / 2;
int pointerY = coordinateY / 2;

int foodX;
int foodY;

bool LEFT = false, RIGHT = false, UP = false, DOWN = false;

void input()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		LEFT = true;
		RIGHT = false;
		UP = false;
		DOWN = false;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		RIGHT = true;
		LEFT = false;
		UP = false;
		DOWN = false;
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		UP = true;
		RIGHT = false;
		LEFT = false;
		DOWN = false;
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		DOWN = true;
		RIGHT = false;
		LEFT = false;
		UP = false;
	}
}

void genFoodX()
{
	foodX = rand() % coordinateX;
}

void genFoodY()
{
	foodY = rand() % coordinateY;
}

int x = 0;

void isEaten()
{
	if (pointerX == foodX && pointerY == foodY)
	{
		nails++;
		x = 0;
	}
}

void isDead(){
if (pointerX == coordinateX || pointerX == -2)
	{
		if (pointerY <= coordinateY || pointerY == -2)
		{
			isGameOver = true;
			
		}
	}
	else if (pointerY == coordinateY || pointerY == -2)
	{
		if (pointerX <= coordinateX || pointerX == -2)
		{
			isGameOver = true;
		
		}
	}
}

void draw()
{
	if (x == 0) {
		genFoodX();
		genFoodY();
		x = 1;
	}
	system("cls");
	for (i = 0; i <= coordinateX; i++) cout << "#";
	cout << endl;

	for (i = 0; i < coordinateY; i++)
	{
		for (j = 0; j <= coordinateX; j++)
		{
			if (j == 0) cout << "#";		
			else if (j == pointerX && i == pointerY){
					cout << "@";
			}
			else if (j == foodX && i == foodY) cout << "*";
			else if (j == coordinateX) cout << "#";
			else cout << " ";
		}
		cout << endl;
	}

	for (i = 0; i <= coordinateX; i++) cout << "#";
	cout << endl;
	cout << "Score: " << score << endl;
	if (LEFT) pointerX--;
	else if (RIGHT) pointerX++;
	else if (UP) pointerY--;
	else if (DOWN) pointerY++;
    
	

	
}

int main()
{
	isGameOver = false;
	while (!isGameOver)
	{
		draw();
		isDead();
		isEaten();	
		Sleep(30);
		input();
	}
	cout<< "Your point(s): " << nails -1 << endl;
	system("pause");
}
