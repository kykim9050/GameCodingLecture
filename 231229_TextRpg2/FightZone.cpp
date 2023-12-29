#include "FightZone.h"
#include <conio.h>
#include <iostream>
#include "Player.h"

FightZone::FightZone()
{
	NewMonster.SetName("Monster");
}

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{
		int Input = _getch();
	}

	system("cls");
	_Second.DamageLogic(_First);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	if (true == _Second.IsDeath())
	{
		printf_s("게임 종료\n");
		return true;
	}


	{
		int Input = _getch();
	}

	system("cls");
	_First.DamageLogic(_Second);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	_Second.DamageRender();
	if (true == _First.IsDeath())
	{
		printf_s("게임 종료\n");
		return true;
	}
	{
		int Input = _getch();
	}
	system("cls");

	return false;
}

void FightZone::In(Player& _Player)
{
	// Fight 존에 들어갈때마다 몬스터의 피가 100으로 차있게 한다.
	NewMonster.SetHpMax();
	
	while (true)
	{

		_Player.StatusRender();
		NewMonster.StatusRender();

		// 선공 후공이 결정 나고
		// 조건에 따라서

		bool IsEnd = false;

		if (_Player.GetRandomSpeed() >= NewMonster.GetRandomSpeed())
		{
			printf_s("플레이어의 선공\n");
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else 
		{
			printf_s("몬스터의 선공\n");
			IsEnd = FightLogic(NewMonster, _Player, _Player, NewMonster);
		}

			if (true == IsEnd)
			{
				// 만약 몬스터의 hp가 0이하가 되면 몬스터가 랜덤하게 돈을 반환한다.
				if (0 >= NewMonster.GetHp())
				{
					_Player.AddGold(NewMonster.RandomGold(10000, 50000));
				}
				return;
			}
	}

}