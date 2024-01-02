#include "Player.h"
#include <iostream>

Player::Player()
{
	// ���� �׽�Ʈ �ڵ�
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

void Player::StatusRenderStart()
{
	printf_s("���� %d\n", Level);
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt() + Weapon.GetEquipUp();
	return CurDamage;
}

void Player::FightEnd(FightUnit& _Ohter)
{
	int Gold = _Ohter.GetGold();
	printf_s("�÷��̾ %d ��带 �������ϴ�.\n", Gold);
	AddGold(Gold);

	// ���ͷκ��� Exp�� ���
	// Exp�� ���ϱ�
	AddExp(_Ohter.GetExp());

	if (LevelUpExp <= Exp)
	{
		// 1. ������ �Լ� ȣ��
		while (Exp > LevelUpExp) {
			
			Exp -= LevelUpExp;
			LevelUpExp += 1000;

			//		�������ϸ� ���ݵ� �߰�
			LevelUp();
			// 2 ������ �� ����ġ �������� �����
			// 3. ������ ����ġ�� ���ŵ� ����ġ���� ���������� ���ѹݺ�
		}

	}
	// ���Ͱ� �� ����ġ�� _Ohter.GetExp();
	// AddExp(_Ohter.GetExp());
	// ���� ����ġ GetExp();

	// ���� �ɷ�ġ�� �󸶳� ��½�ų��.
	// �� ��ȹ���� ����. ��¸� ��Ű����.

	// LevelUpExp �񱳸� �ؼ�
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