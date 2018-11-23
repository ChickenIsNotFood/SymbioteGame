
#include<iostream>
using namespace std;

bool isDead(int coordinateY, int coordinateX, int pointerX, int pointerY) {
	if (pointerX == coordinateX + 1 || pointerX <= 0)
	{
		if (pointerY <= coordinateY || pointerY <= -2)
		{
			return true;

		}
	}
	else if (pointerY == coordinateY || pointerY <= -2)
	{
		if (pointerX <= coordinateX + 1 || pointerX <= 0)
		{
			return true;

		}
	}
	return false;
}

void isEaten(int pointerX, int foodX, int pointerY, int foodY, int *nails, int *x)
{
	if (pointerX == foodX + 1 && pointerY == foodY)
	{
		*nails =*nails+1;
		*x = 0;
	}
}
