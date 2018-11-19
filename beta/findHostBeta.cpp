#include<iostream>
#include<conio.h>
#include<Windows.h>
#include <fstream.h>
#include <time.h>
using namespace std;

const int coordinateX = 30;
const int coordinateY = 18;

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
	if (GetAsyncKeyState(VK_LEFT) && !RIGHT)
	{
		LEFT = true;
		RIGHT = false;
		UP = false;
		DOWN = false;
	}
	else if (GetAsyncKeyState(VK_RIGHT) && !LEFT)
	{
		RIGHT = true;
		LEFT = false;
		UP = false;
		DOWN = false;
	}
	else if (GetAsyncKeyState(VK_UP) && !DOWN)
	{
		UP = true;
		RIGHT = false;
		LEFT = false;
		DOWN = false;
	}

	else if (GetAsyncKeyState(VK_DOWN) && !UP)
	{
		DOWN = true;
		RIGHT = false;
		LEFT = false;
		UP = false;
	}
}

void genFoodX()
{
	 srand (time(NULL));	
	foodX = rand() % coordinateX;
}

void genFoodY()
{
	srand (time(NULL));	
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
	cout << "your score: " << nails -1 << " High score: "<< getHighScore()<<endl;
	if (LEFT) pointerX--;
	else if (RIGHT) pointerX++;
	else if (UP) pointerY--;
	else if (DOWN) pointerY++;
    
	

	
}

int  getHighScore(){
ifstream fin ("highscore.txt");
string str ="";

if (fin.is_open())
{
while (!fin.eof())
{
getline(fin, str);
  str+=str;
}
fin.close();
}
else
{
cout << "File not found\n";
cout<< "Creating new file..."<<endl;
ofstream outfile ("highscore.txt");
outfile << "0";
outfile.close();
getHighScore();
}

return stoi(str);
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
	if (nails-1 > getHighScore()){
        cout << "Congrats, you beat the highscore!!!";
	ofstream ft("highscore.txt");
        ft << nails-1
         << endl;
        ft.close();
	}
       cout << getHighScore() <<endl;	
	system("pause");
}
