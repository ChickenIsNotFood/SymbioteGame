#include<iostream>
#include<conio.h>

#define max 100

using namespace std;

const int truc_x = 25;
const int truc_y = 25;

int i, j, diem_so;

bool thua_cmnr;

enum di_chuyen
{
	UP, RIGHT, LEFT, DOWN, STOP
};

struct toa_do
{
	int x;
	int y;
};

struct con_ran
{
	int duoi_ran;
	toa_do toa_do;
	di_chuyen _di_chuyen;
};

struct thuc_an
{
	toa_do toa_do;
};

con_ran ran;
con_ran duoi[max];
thuc_an do_an;

void ve_cai_khung()
{
	//khung_tren
	for (i = 0; i < truc_x; i++)
	{
		cout << "#";
	}
	cout << endl;
	//khung_trai_phai
	for (int i = 2; i < truc_x; i++)
	{
		cout << "#";
		for (int j = 1; j < truc_y - 1; j++)
		{
			cout << " ";
		}
		cout << "#" << endl;
	}
	//khung_duoi
	for (i = 0; i < truc_x; i++)
	{
		cout << "#";
	}
	cout << endl;
}

void ran_ngo_nguay()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case'w':
			ran._di_chuyen = UP;
			break;
		case's':
			ran._di_chuyen = DOWN;
			break;
		case'a':
			ran._di_chuyen = LEFT;
			break;
		case'd':
			ran._di_chuyen = RIGHT;
			break;
		case'x':
			thua_cmnr = true;
		default:
			break;
		}
	}
}

void ia_ra_ran()
{
	ran.toa_do.x = truc_x / 2;
	ran.toa_do.y = truc_y / 2;
	for (i = 0; i < truc_x; i++)
	{
		for (j = 0; j < truc_y; j++)
		{
			if (ran.toa_do.x == i && ran.toa_do.y == j)
			{
				cout << "@";
			}
		}
	}
}

void ia_ra_thuc_an()
{
	do_an.toa_do.x = rand() % truc_x-1;
	do_an.toa_do.y = rand() % truc_y - 1;
	
	for (i = 0; i < truc_x; i++)
	{
		for (j = 0; j < truc_y; j++)
		{
			if (ran.toa_do.x == i && ran.toa_do.y == j)
			{
				cout << "*";
			}
		}
	}
}

void brain_cua_ran()
{
	switch (ran._di_chuyen)
	{
	case UP:
		ran.toa_do.y--;
		break;
	case DOWN:
		ran.toa_do.y++;
		break;
	case LEFT:
		ran.toa_do.x--;
		break;
	case RIGHT:
		ran.toa_do.x++;
		break;
	default:
		break;
	}
	if (ran.toa_do.x == do_an.toa_do.x && ran.toa_do.y == do_an.toa_do.y)
	{
		ran.duoi_ran++;
	}

	for (i = 0; i < ran.duoi_ran; i++)
	{
		ran.toa_do.x = duoi[i].toa_do.x;
		ran.toa_do.y = duoi[i].toa_do.y;
	}
}

int main()
{
	thua_cmnr = false;
	ve_cai_khung();
	while (!thua_cmnr)
	{
		ia_ra_ran();
		ran_ngo_nguay();
		ia_ra_thuc_an();
		brain_cua_ran();
	}

	_getch();
	return 0;
}
