//symbiote
#include<iostream>
#include<iomanip>

using namespace std;

 char frame[15][30] ;
 int i, j;

void setup()
{
	char fruit = '*';
	char headSymbiote = '@';
}

void draw()
{

	//khung_tren
	for (i = 0; i < 30; i++)
	{
		frame[0][i] = '#';
	}
	cout << endl;
	//khung_trai
	for (i = 0; i < 15; i++)
	{
		frame[i][0] = '#';
	}
	//khung_phai
	for (i = 1; i < 14; i++)
	{
		for (j = 1; j < 30; j++)
		{
		   frame[i][j] =' ';
		}
	}
	//khung_duoi
	for (i =0; i < 30; i++){
	  frame[15][i] = '#';
	}
	// print out the frame
	for (i = 0; i<15; i++)
             for (j = 0; j< 30; j++){
	     cout << frame[i][j];
	    }

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
