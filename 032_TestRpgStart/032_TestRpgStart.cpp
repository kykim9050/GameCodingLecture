﻿// 032_TextRpgStart.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

// const를 붙인이유
// 보여주기만 하는 함수인데 수정할 생각이 없는 함수
void StatusRender(const char* _Name, int _Att, int _Hp)
{
    // 콘솔창은 특수문자를 통해서 특수한 출력기호를 사용할수 있는데.
    // 전부다 \ 백스페이스키 역슬레시를 사용해서 표현합니다.
    // %d <= 2글자 맡고
    // \n <= 1글자로 봅니다. 콘솔창이 한글자로 봅니다.
    // \n => 엔터를 쳐라. 라인을 바꿔라.

    int Size = printf_s("%s ", _Name);
    for (int i = 0; i < 50 - Size; i++)
    {
        printf_s("-");
    }

    printf_s("\n");
    printf_s("공격력 %d\n", _Att);
    printf_s("체력 %d\n", _Hp);

    for (int i = 0; i < 50; i++)
    {
        printf_s("-");
    }

    printf_s("\n");
}


// 공격의 행동을 화면에 랜더링 하는 함수
void DamageRender(const char* _Name, const int& _Att)
{
    printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", _Name, _Att);
}
// 실제 데미지를 데이터적으로 주는 함수
void DamageLogic(const int& _Att, int& _DefHp)
{
    // 축약연산자라고 부르기도 한다.
    // - 뿐만 아니라 더하기 나누기 곱하기 비트단위등등 거의 모든 연산의
    // 축약 연산자가 존재합니다.
    _DefHp -= _Att;
    // _DefHp = _DefHp - _Att;
}

void Damage(const char* _Name, const int& _Att, int& _DefHp)
{
    DamageRender(_Name, _Att);
    DamageLogic(_Att, _DefHp);
}

int main()
{
    // 먼저 존재하게 하기 위해서
    // 상태를 만들었다.
    char PlayerName[100] = "Fighter";
    int PlayerHp = 100;
    int PlayerAtt = 10;

    char MonsterName[100] = "Orc";
    int MonsterHp = 50;
    int MonsterAtt = 5;

	StatusRender(PlayerName, PlayerAtt, PlayerHp);
	StatusRender(MonsterName, MonsterAtt, MonsterHp);

    while (true)
    {
        // PHASE 1
        {
            int Input = _getch();
        }
        system("cls");

        

        DamageLogic(PlayerAtt, MonsterHp);

        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);

        DamageRender(PlayerName, PlayerAtt);

        // PHASE 2
        {
            int Input = _getch();
        }
        system("cls");

        DamageLogic(MonsterAtt, PlayerHp);

		StatusRender(PlayerName, PlayerAtt, PlayerHp);
		StatusRender(MonsterName, MonsterAtt, MonsterHp);

        DamageRender(MonsterName, MonsterAtt);
    }



    //DamageRender(PlayerName, PlayerAtt);
    //DamageLogic(PlayerAtt, MonsterHp);

    //DamageRender(MonsterName, MonsterAtt);
    //DamageLogic(MonsterAtt, PlayerHp);
}
