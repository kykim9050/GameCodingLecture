#include "Monster.h"
#include "ContentsEnum.h"


void Monster::Update()
{

	if (0 >= MoveCount)
	{
		MoveCount = 10;

		if (Direction == Right)
		{
			Direction = Left;
		}
		else
		{
			Direction = Right;
		}
	}

	AddPos(Direction);
	--MoveCount;
	


	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (nullptr != CollisionObject)
	{
		Destroy();
		CollisionObject->Destroy();
	}

}