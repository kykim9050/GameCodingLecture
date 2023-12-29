#include "StatusUnit.h"
#include <iostream>


void StatusUnit::StatusRender()
{
	// 메모리에 관련된 명확한 설명은 안한 상태지만
	// 자신의 맴버함수에서 자신의 맴버변수는 자유롭게 사용이 가능합니다.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	printf_s("공격력 %d~%d\n", MinAtt, MaxAtt);
	printf_s("체력 %d\n", Hp);
	printf_s("골드 %d\n", Gold);

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}

int StatusUnit::RandomGold(int _MinVal, int _MaxVal)
{
	int ReturnGold = (rand() % (_MaxVal- _MinVal)) + _MinVal;

	return ReturnGold;
}

int StatusUnit::AddGold(int _Gold)
{
	Gold += _Gold;

	return _Gold;
}

void StatusUnit::SpentGold(int _MinusGold)
{
	if (0 >= (Gold - _MinusGold))
	{
		printf_s("더이상 Gold를 소모할 수 없습니다");
		return;
	}

	Gold -= _MinusGold;
}