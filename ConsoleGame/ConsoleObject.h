#pragma once
#include "Math.h"

// �ڽĵ��� ���������� �������� ����� ����� ���� �Ѵ�.
class ConsoleObject
{
public:
	//ConsoleObject();

	//ConsoleObject(const int2& _StartPos, char _RenderChar);

	int2 GetPos();

	char GetRenderChar();

protected:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';

private:
};

