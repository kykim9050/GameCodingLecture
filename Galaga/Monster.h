#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Monster : public ConsoleObject
{
protected:
	void Update() override;

	int MoveCount = 0;
	int2 Direction = Left;
};

