#pragma once
#include "NameUnit.h"

class StatusUnit : public NameUnit
{
public:
	void StatusRender();

	inline void HpReset()
	{
		Hp = MaxHp;
	}

	inline void MaxHpSet(int _NewMaxHp)
	{
		MaxHp = _NewMaxHp;

		HpReset();
	}

	inline void MinAttSet(int _NewMinAtt)
	{
		MinAtt = _NewMinAtt;
	}

	inline int MinAttGet() const
	{
		return MinAtt;
	}

	inline void MaxAttSet(int _NewMaxAtt)
	{
		MaxAtt = _NewMaxAtt;
	}

	inline int MaxAttGet() const
	{
		return MaxAtt;
	}


	inline void AddGold(int _Gold)
	{
		Gold += _Gold;
	}

	inline int GetGold() 
	{
		return Gold;
	}

	void RandomGold(int _Min, int _Max);




protected:
	int Hp = 100;
	int MaxHp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 20; // 0~20
	int Gold = 0;
};

