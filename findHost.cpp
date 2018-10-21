//symbiote
#include<iostream>
#include<iomanip>

using namespace std;

const int chieuDai = 15;
const int chieuRong = 30;

int i, j;

void setup()
{
	char fruit = '*';
	char headSymbiote = '@';
}

void draw()
{
	//khung_tren
	for (i = 0; i < chieuRong; i++)
	{
		cout << "#";
	}
	cout << endl;
	//khung_trai
	for (i = 0; i < chieuDai; i++)
	{
		cout << '#' << endl;
	}
	//khung_phai
	for (i = 0; i < chieuRong; i++)
	{
		for (j = 0; j < chieuDai; j++)
		{
			cout << '#' << endl;
		}
	}
	//khung_duoi
	for (i = 0; i < chieuRong; i++)
	{
		cout << "#";
	}
	cout << endl;

}

void input()
{

}

void logic()
{

}


int main()
{
	draw();
	system("pause");
	return 0;
}
