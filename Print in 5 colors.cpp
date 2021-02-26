#include "pch.h"
#include <iostream>
#include <windows.h>

void SetColor(int a) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
using namespace std;

int main()
{
	for (int n = 1; n < 6; n++) {
		SetColor(n);//sets the colour
		std::cout << "This is color " << n << "." << std::endl;
	}

	return 0;
}