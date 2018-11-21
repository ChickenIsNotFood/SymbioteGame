
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include<time.h>
#include<string>
#include <vector> 

using namespace std;

const int coordinateX = 30;
const int coordinateY = 18;

bool isGameOver;

int i, j;

int nails = 1;
int pointerX[540];
int pointerY[540];

int foodX;
int foodY;

bool LEFT = false, RIGHT = false, UP = false, DOWN = false;
void poop_snake() {

	LEFT = false;
	RIGHT = false;
	UP = false;
	DOWN = false;
	pointerX[0]=coordinateX / 2;
	pointerY[0]=coordinateY / 2;
}
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
	srand(time(NULL));
	foodX = rand() % coordinateX + 1;
}

void genFoodY()
{
	srand(time(NULL));
	foodY = rand() % coordinateY +1;
}

int x = 0;

void isEaten()
{
	if (pointerX[0] == foodX && pointerY[0] == foodY)
	{

		nails++;
		/*pointerX[nails-1] = foodX;
		pointerY[nails-1] = foodY;*/
	
		x = 0;
	}
}

void isDead() {
	if (pointerX[0] == coordinateX || pointerX[0] <= 0)
	{
		if (pointerY[0] <= coordinateY || pointerY[0] <= -2)
		{
			isGameOver = true;

		}
	}
	else if (pointerY[0] == coordinateY || pointerY[0] <= -2)
	{
		if (pointerX[0] <= coordinateX || pointerX[0] <= 0)
		{
			isGameOver = true;

		}
	}
}

unsigned int getHighScore() {
	ifstream fin("highscore.txt");
	string str = "";

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, str);
			str = str;
		}
		fin.close();
	}
	else
	{
		cout << "File not found\n";
		cout << "Creating new file..." << endl;
		ofstream outfile("highscore.txt");
		outfile << "0";
		outfile.close();
	}
	unsigned int c = 0;
	try {
		c = stoi(str);
	}
	catch (exception& e) {
		cout << "Cannot covert int to string\n";
	}

	return c;
}

void draw()
{
	if (x == 0) {
		genFoodX();
		genFoodY();
		x = 1;
	}
	
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);
	for (i = 0; i <= coordinateX; i++) cout << "#";
	cout << endl; 

	for (i = 0; i < coordinateY; i++)
	{
		for (j = 0; j <= coordinateX; j++)
		{
			for (int an = 0; an < nails; an++)
			if (j == pointerX[an] && i == pointerY[an]) {
				SetConsoleTextAttribute(hConsole, 12);
				cout << "@";
				SetConsoleTextAttribute(hConsole, 2);
				
			}
			if (j == 0) {
				SetConsoleTextAttribute(hConsole, 2);
				cout << "#";
			
			}
			else if (j == foodX && i == foodY ) {
				SetConsoleTextAttribute(hConsole, 13);
				cout << "*";
			}
			else if (j == coordinateX) {
			
				cout << "#";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 2);

	for (i = 0; i <= coordinateX; i++) cout << "#";
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "your score: " << nails - 1 << " High score: " << getHighScore() << endl;
	if (LEFT) {
		pointerX[0]--;
		/*
		if (UP) {
			for (int i =2; i<nails; i++)
				pointerY[nails-1]--;
		}
		else if (DOWN) {
			for (int i = 2; i < nails; i++)
			pointerY[nails-1]++;
		}
		for (int i = 2; i < nails; i++)
		if (pointerY[nails-1] == pointerY[nails-2]) {
			pointerY[nails-1] = pointerY[nails-2];
			pointerX[nails-1] = pointerX[nails-2] +1 ;
		}*/
		for (int bob =1; bob < nails; bob++) {
		
			pointerX[bob] = pointerX[bob - 1] +1;
			pointerY[bob] = pointerY[bob - 1];
		}
	}
	else if (RIGHT) {
		pointerX[0]++;
		
		/*if (UP) {
			for (int i = 2; i < nails; i++)
			pointerY[nails-1]--;
		}
		else if (DOWN) {
			for (int i = 2; i < nails; i++)
			pointerY[nails-1]++;
		}
		for (int i = 2; i < nails; i++)
		if (pointerY[nails-1] == pointerY[nails-2] ) {
			pointerY[nails-1] = pointerY[nails-2];
			pointerX[nails-1] = pointerX[nails-2] - 1;
		}*/

		for (int bob = 1; bob < nails; bob++) {
			pointerX[bob] = pointerX[bob - 1] - 1;
			pointerY[bob] = pointerY[bob - 1];
			
		}
		
	}
	else if (UP) {
		pointerY[0]--;
/*
		if (LEFT) {
			for (int i = 2; i < nails; i++)
			pointerX[nails-1]--;
		}
		else if (RIGHT) {
			for (int i = 2; i < nails; i++)
			pointerX[nails-1]++;
		}
		for (int i = 2; i < nails; i++)
		if (pointerX[nails-1] == pointerX[nails-2]) {
			pointerY[nails-1] = pointerY[nails-2] +1 ;
			pointerX[nails-1] = pointerX[nails-2];
		}*/
		for (int bob = 1; bob < nails; bob++) {
			pointerY[bob] = pointerY[bob - 1] + 1;
			pointerX[bob] = pointerX[bob - 1];
		}
	}
	else if (DOWN) {
		pointerY[0]++;
		/*
		if (LEFT) {
			for (int i = 2; i < nails; i++)
			pointerX[nails-1]--;
		}
		else if (RIGHT ) {
			for (int i = 2; i < nails; i++)
			pointerX[nails-1]++;
		}
		for (int i = 2; i < nails; i++)
		if ((pointerX[nails-1] == pointerX[nails-2])) {
			pointerY[nails-1] = pointerY[nails-2] - 1;
			pointerX[nails-1] = pointerX[nails-2];
		}*/
		for (int bob = 1; bob < nails; bob++) {
			pointerY[bob] = pointerY[bob - 1] - 1;
			pointerX[bob] = pointerX[bob - 1];
		}
	}

}
void doingit() {
	isGameOver = false;
	poop_snake();
	nails = 1;
	while (!isGameOver)
	{
		
		draw();
		isDead();
		isEaten();
		Sleep(30);
		input();
	}
	cout << "Your point(s): " << nails - 1 << endl;
	if (nails - 1 > getHighScore()) {
		cout << "Congrats, you beat the highscore!!!";
		ofstream ft("highscore.txt");
		ft << nails - 1;
		ft.close();
	}
	char c = 'n';
	cout <<"Highscore: "<< getHighScore() << endl;
	cout << "Do you want to continue?(y/n): ";
	cin >> c;
	if (c == 'y' || c == 'Y') {
		doingit();
	}

}

int main()
{
	doingit();
	system("pause");
}
