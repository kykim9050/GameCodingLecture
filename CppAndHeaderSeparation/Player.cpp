#include "Player.h"

Player::Player()
{
}

Player::Player(char _RenderChar)
	: RenderChar(_RenderChar)
{
}

void Player::Update()
{
}

void Player::SetBulletFire(bool* _IsFire)
{
	if (nullptr == _IsFire)
	{
		return;
	}

	IsFire = _IsFire;
}