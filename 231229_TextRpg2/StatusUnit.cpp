#include "StatusUnit.h"
#include <iostream>


void StatusUnit::StatusRender()
{
	// �޸𸮿� ���õ� ��Ȯ�� ������ ���� ��������
	// �ڽ��� �ɹ��Լ����� �ڽ��� �ɹ������� �����Ӱ� ����� �����մϴ�.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	printf_s("���ݷ� %d~%d\n", MinAtt, MaxAtt);
	printf_s("ü�� %d\n", Hp);
	printf_s("��� %d\n", Gold);

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
		printf_s("���̻� Gold�� �Ҹ��� �� �����ϴ�");
		return;
	}

	Gold -= _MinusGold;
}