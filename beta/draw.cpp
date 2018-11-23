#include "pch.h"
#include <iostream>
#include "write.h"
#include "windows.h"
#include "gen.h"
using namespace std;

void draw(int *foodX, int *foodY, int *x, int coordinateX, int coordinateY, int i, int j, int *pointerX, int *pointerY, int nails, bool UP, bool DOWN, bool LEFT, bool RIGHT, bool movu, bool movd, bool movl, bool movr)
{
	if (*x == 0) {
		*foodX = genFoodX(coordinateX);
		*foodY = genFoodY(coordinateY);
		*x = 1;
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
					cout << "\b@";
					SetConsoleTextAttribute(hConsole, 2);

				}
			if (j == 0) {
				SetConsoleTextAttribute(hConsole, 2);
				cout << "#";

			}
			else if (j == *foodX && i == *foodY) {
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
		int checkY = pointerY[0];
		pointerX[0]--;

		for (int bob = 1; bob <= nails; bob++) {
			if (bob == 1) {
				pointerX[bob] = pointerX[bob - 1] + 1;
				pointerY[bob] = pointerY[bob - 1];
			}

			else if (movu) {
				if (pointerY[bob] != checkY) {
					pointerX[bob] = pointerX[bob - 1];
					pointerY[bob]--;
				}
				if (pointerY[bob] == checkY) {
					pointerX[bob] = pointerX[bob - 1] + 1;
				}
			}
			else if (movd) {
				if (pointerY[bob] != checkY) {
					pointerX[bob] = pointerX[bob - 1];
					pointerY[bob]++;
				}
				if (pointerY[bob] == checkY) {
					pointerX[bob] = pointerX[bob - 1] + 1;
				}
			}
		}

	}
	else if (RIGHT) {
		int checkY = pointerY[0];
		pointerX[0]++;

		for (int bob = 1; bob <= nails; bob++) {
			if (bob == 1) {
				pointerX[bob] = pointerX[bob - 1] - 1;
				pointerY[bob] = pointerY[bob - 1];
			}
			else if (movu) {
				if (pointerY[bob] != checkY) {
					pointerX[bob] = pointerX[bob - 1];
					pointerY[bob]--;
				}
				if (pointerY[bob] == checkY) {
					pointerX[bob] = pointerX[bob - 1] - 1;
				}
			}
			else if (movd) {
				if (pointerY[bob] != checkY) {
					pointerX[bob] = pointerX[bob - 1];
					pointerY[bob]++;
				}
				if (pointerY[bob] == checkY) {
					pointerX[bob] = pointerX[bob - 1] - 1;
				}
			}

		}

	}
	else if (UP) {
		int checkX = pointerX[0];
		pointerY[0]--;

		for (int bob = 1; bob <= nails; bob++) {
			if (bob == 1) {
				pointerY[bob] = pointerY[bob - 1] + 1;
				pointerX[bob] = pointerX[bob - 1];
			}
			else if (movr) {
				if (pointerX[bob] != checkX) {
					pointerY[bob] = pointerY[bob - 1];
					pointerX[bob]++;
				}
				if (pointerX[bob] == checkX) {
					pointerY[bob] = pointerY[bob - 1] + 1;
				}
			}
			else if (movl) {
				if (pointerX[bob] != checkX) {
					pointerY[bob] = pointerY[bob - 1];
					pointerX[bob]--;
				}
				if (pointerX[bob] == checkX) {
					pointerY[bob] = pointerY[bob - 1] + 1;
				}
			}
		}
	}
	else if (DOWN) {
		int checkX = pointerX[0];
		pointerY[0]++;

		for (int bob = 1; bob <= nails; bob++) {
			if (bob == 1) {
				pointerY[bob] = pointerY[bob - 1] - 1;
				pointerX[bob] = pointerX[bob - 1];
			}
			else if (movr) {
				if (pointerX[bob] != checkX) {
					pointerY[bob] = pointerY[bob - 1];
					pointerX[bob]++;
				}
				if (pointerX[bob] == checkX) {
					pointerY[bob] = pointerY[bob - 1] - 1;
				}
			}
			else if (movl) {
				if (pointerX[bob] != checkX) {
					pointerY[bob] = pointerY[bob - 1];
					pointerX[bob]--;
				}
				if (pointerX[bob] == checkX) {
					pointerY[bob] = pointerY[bob - 1] - 1;
				}
			}
		}
	}

}
