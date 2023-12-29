#pragma once
#include <iostream>
#include "Math.h"


class ConsoleScreen
{
public:

	ConsoleScreen(char _BaseChar);

	void PrintScreen(){}

	void ClearScreen(){}

	void SetPixel(const int2& _Position, char _Char){}

	void SetPixel(int _X, int _Y, char _Char){}

protected:

private:
	char Arr[ScreenY][ScreenX] = { 0, };
	char BaseCh = ' ';
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
};