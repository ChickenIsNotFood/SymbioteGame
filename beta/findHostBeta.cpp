#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include "gen.h"
#include "write.h"
#include "iswut.h"
#include "inputt.h"
#include "draw.h"
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
bool movu = false;
bool movd = false;
bool movl = false;
bool movr = false;
int x = 0;

void doingit() {
	isGameOver = false;
	poop_snake(&LEFT, &RIGHT, &UP, &DOWN, pointerX, pointerY, coordinateX, coordinateY);
	nails = 1;
	while (!isGameOver)
	{
		draw(&foodX, &foodY,&x, coordinateX, coordinateY, i, j, pointerX, pointerY, nails, UP, DOWN, LEFT, RIGHT, movu, movd, movl,  movr);
		isGameOver = isDead(coordinateY, coordinateX, pointerX[0], pointerY[0]);
		isEaten(pointerX[0], foodX, pointerY[0], foodY, &nails, &x);
		Sleep(30);
		input(&LEFT, &RIGHT, &UP, &DOWN,&movu, &movd, &movl, &movr );
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
