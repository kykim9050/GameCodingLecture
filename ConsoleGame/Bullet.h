#pragma once
// ����� ������ ����� �߰��ؾ� �մϴ�.
#include "ConsoleObject.h"

class Bullet : public ConsoleObject
{
public:
	Bullet(const int2& _StartPos, char _RenderChar);

	bool& GetIsFireRef();

private:
	bool IsFire = false;
};
