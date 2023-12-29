#pragma once
#include "NameUnit.h"

class Weapon : public NameUnit
{
public:
	inline int GetAtt() const
	{
		return Att;
	}

	inline void SetAtt(int _Att) 
	{
		Att = _Att;
	}

	inline int GetEquipUp() const
	{
		return EquipUp;
	}

	inline void SetEquipgrade(int _EquipUp)
	{
		EquipUp = _EquipUp;
	}

	void WeaponGradeUP();

	void SetEquipGradeDown(int _DownVal);


private:
	int EquipUp = 0;
	int Att;
};

