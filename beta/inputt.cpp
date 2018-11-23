#include <windows.h>
#include <iostream>
using namespace std;
void input(bool *LEFT, bool *RIGHT, bool *UP, bool *DOWN, bool *movu, bool *movd, bool *movl, bool *movr)
{
	if (GetAsyncKeyState(VK_LEFT) && !*RIGHT)
	{
		*LEFT = true;
		if (*UP) {
			*movu = true;
			*movd = false;
			*movl = false;
			*movr = false;
		}
		else if (*DOWN) {
			*movd = true;
			*movu = false;
			*movl = false;
			*movr = false;
		}
		*RIGHT = false;
		*UP = false;
		*DOWN = false;
	}
	else if (GetAsyncKeyState(VK_RIGHT) && !*LEFT)
	{
		if (*UP) {
			*movu = true;
			*movd = false;
			*movl = false;
			*movr = false;
		}
		else if (*DOWN) {
			*movd = true;
			*movu = false;
			*movl = false;
			*movr = false;
		}
		*RIGHT = true;
		*LEFT = false;
		*UP = false;
		*DOWN = false;
	}
	else if (GetAsyncKeyState(VK_UP) && !*DOWN)
	{
		if (*LEFT) {
			*movu = false;
			*movd = false;
			*movl = true;
			*movr = false;
		}
		else if (*RIGHT) {
			*movd = false;
			*movu = false;
			*movl = false;
			*movr = true;
		}
		*UP = true;
		*RIGHT = false;
		*LEFT = false;
		*DOWN = false;
	}

	else if (GetAsyncKeyState(VK_DOWN) && !*UP)
	{
		if (*LEFT) {
			*movu = false;
			*movd = false;
			*movl = true;
			*movr = false;
		}
		else if (*RIGHT) {
			*movd = false;
			*movu = false;
			*movl = false;
			*movr = true;
		}
		*DOWN = true;
		*RIGHT = false;
		*LEFT = false;
		*UP = false;
	}
}
