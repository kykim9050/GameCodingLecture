#pragma once
#include <iostream>
#include ".\Math.h"
//#include "..\AAAA.h"

// 시킨대로 했어요 알려준대로 했어요. => 절대 하면 안되는말.

// 전역변수는 영역과 관련없이
// 이름이 위에 있다면 그것을 사용할 수 있다.
const int ScreenX = 20;
const int ScreenY = 12;
const int ScreenXHalf = ScreenX / 2;
const int ScreenYHalf = ScreenY / 2;

class ConsoleScreen
{
public:
	// 생성자를 만든다는것은
	// 내가 만든 생성자 형식으로만 생성해라.
	ConsoleScreen(char _BaseChar);

	void PrintScreen();

	void ClearScreen();

	void SetPixel(const int2& _Position, char _Char);

	void SetPixel(int _X, int _Y, char _Char);

protected:

private:
	char Arr[ScreenY][ScreenX] = { 0, };
	char BaseCh = ' ';
};
