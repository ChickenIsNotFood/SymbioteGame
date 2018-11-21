#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include<time.h>
#include<string>
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
void poop_snake() {
	LEFT = false;
	RIGHT = false;
	UP = false;
	DOWN = false;
	pointerX = coordinateX / 2;
	pointerY = coordinateY / 2;
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
	if (pointerX == foodX && pointerY == foodY)
	{
		nails++;
		x = 0;
	}
}

void isDead() {
	if (pointerX == coordinateX || pointerX <= 0)
	{
		if (pointerY <= coordinateY || pointerY <= -2)
		{
			isGameOver = true;

		}
	}
	else if (pointerY == coordinateY || pointerY <= -2)
	{
		if (pointerX <= coordinateX || pointerX <= 0)
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
			if (j == 0) {
				SetConsoleTextAttribute(hConsole, 2);
				cout << "#";
			}
			else if (j == pointerX && i == pointerY) {
				SetConsoleTextAttribute(hConsole, 12);
				cout << "@";
			}
			else if (j == foodX && i == foodY) {
				SetConsoleTextAttribute(hConsole, 13);
				cout << "*";
			}
			else if (j == coordinateX) cout << "#";
			else cout << " ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 2);

	for (i = 0; i <= coordinateX; i++) cout << "#";
	cout << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << "your score: " << nails - 1 << " High score: " << getHighScore() << endl;
	if (LEFT) pointerX--;
	else if (RIGHT) pointerX++;
	else if (UP) pointerY--;
	else if (DOWN) pointerY++;

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
