#include<time.h>
#include<iostream>
using namespace std;

int genFoodX(int coordinateX)
{
	srand(time(NULL));
	int foodX = rand() % (coordinateX - 1) + 1;
	return foodX;
}

int genFoodY(int coordinateY)
{
	srand(time(NULL));
	int foodY = rand() % (coordinateY - 1) + 1;
	return foodY;
}

void poop_snake(bool *LEFT, bool *RIGHT, bool *UP, bool *DOWN, int *pointerX, int *pointerY, int coordinateX, int coordinateY) {

	*LEFT = false;
	*RIGHT = false;
	*UP = false;
	*DOWN = false;
	pointerX[0] = coordinateX / 2;
	pointerY[0] = coordinateY / 2;
}
