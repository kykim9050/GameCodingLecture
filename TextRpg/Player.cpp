#include "Player.h"
#include <iostream>

Player::Player()
{
	// 지금 테스트 코드
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

void Player::StatusRenderStart()
{
	printf_s("레벨 %d\n", Level);
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp();
	return CurDamage;
}

void Player::FightEnd(FightUnit& _Ohter)
{
	int Gold = _Ohter.GetGold();
	printf_s("플레이어가 %d 골드를 벌었습니다.\n", Gold);
	AddGold(Gold);

	// 몬스터로부터 Exp를 얻고
	// Exp에 더하기
	AddExp(_Ohter.GetExp());

	if (LevelUpExp <= Exp)
	{
		// 1. 레벨업 함수 호출
		while (Exp > LevelUpExp) {
			
			Exp -= LevelUpExp;
			LevelUpExp += 1000;

			//		레벨업하면 스텟도 추가
			LevelUp();
			// 2 레벨업 후 경험치 나머지는 재산정
			// 3. 나머지 경험치가 갱신된 경험치보다 작을떄까지 무한반복
		}

	}
	// 몬스터가 준 경험치죠 _Ohter.GetExp();
	// AddExp(_Ohter.GetExp());
	// 나의 경험치 GetExp();

	// 나의 능력치를 얼마나 상승시킬지.
	// 다 기획적인 거죠. 상승만 시키세요.

	// LevelUpExp 비교를 해서
}

void Player::LevelUp()
{
	Level += 1;
	MinAtt += 5;
	MaxAtt += 5;
	Speed += 5;

	SetMaxHp(GetMaxHp() + 5);
	HpReset();
}