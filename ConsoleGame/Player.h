#pragma once
#include "ConsoleObject.h"

#include <conio.h>

class Player : public ConsoleObject
{
public:
	Player();

	Player(const int2& _StartPos, char _RenderChar);

	void Update();

	void SetBulletFire(bool* _IsFire);

private:

	bool* IsFire = nullptr;
};
