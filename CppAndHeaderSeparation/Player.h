// ������� �Ʒ��� #pragma once�� �� �־�� �մϴ�.
#pragma once
#include "Math.h"

// ������� ���� �����ϴ�.
class Player
{
public:
	//�Լ����� �������� �� �Ǿ��ִ� ��Ȳ�̴�.
	// ������ �� �����ϰ�
	Player();
	Player(char _RenderChar);

	// ������ ������ �Լ�.
	// ����� ������ �и��ϸ� inline�� ���� �ʴ´�.
	// ���� ������ ������ �Լ��� ����� ������ �и����� �ʾƿ�.
	// ���� Get�� Set�Լ� Ȥ�� Get�� �ϴ� ����� �ִ�.
	inline char GetRenderChar()
	{
		return RenderChar;
	}

	void Update();
	void SetBulletFire(bool* _IsFire);

private:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
	bool* IsFire = nullptr;
};

