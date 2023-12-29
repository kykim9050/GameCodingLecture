#pragma once
#include "NameUnit.h"

class StatusUnit : public NameUnit
{
public:
	void StatusRender();

	inline int GetHp() const
	{
		return Hp;
	}

	inline void SetHpMax()
	{
		Hp = MaxHp;
	}
	inline int GetGold() const
	{
		return Gold;
	}

	void SpentGold(int _MinusGold);

	int RandomGold(int _MinVal, int _MaxVal);


	int AddGold(int _Gold);

protected:
	int Hp = 100;
	const int MaxHp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 20; // 0~20
	int Gold = 0;
};

