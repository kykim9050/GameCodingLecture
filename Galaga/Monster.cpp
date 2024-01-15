#include "Monster.h"
#include "ContentsEnum.h"


void Monster::Update()
{

	if (0 >= MoveCount)
	{

		if (Direction == Right)
		{
			AddPos(Down);
			Direction = Left;
		}
		else
		{
			AddPos(Down);
			Direction = Right;
		}
		MoveCount = 10;
	}
	else
	{
		AddPos(Direction);
		--MoveCount;
	}


	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (nullptr != CollisionObject)
	{
		Destroy();
		CollisionObject->Destroy();
	}

}