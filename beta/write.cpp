
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

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
