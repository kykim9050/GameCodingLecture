#include "Monster.h"

void Monster::FightStart(FightUnit& _Player)
{
	HpReset(/*this*/);
	RandomGold(1000, 10000);
	RandomExp(1000, 2000);
}

void Monster::FightEnd(/*Monster* const this,*/ FightUnit& _Player)
{
	// �����ϰ� ����ġ�� ���ؾ� �Ѵ�.
	
	/*NewMonster.*/
	/*this->*/
}