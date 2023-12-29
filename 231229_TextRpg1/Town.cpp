#include "Town.h"
#include <iostream>
#include <conio.h>
#include "Player.h"

void Town::WeaponUp(Player& _Player)
{
    // 여러분들이 건드려야 하는 부분은 여기 뿐입니다.

    // 1. 플레이어의 무기의 강화 상태를 보여준다.    V
    // 기존 그려졌던 랜더링을 전부다 지우고.    V
    // 1번선택지는 강화        V
    //   30강에 도달한 부기는 강화가 안된다고 띄워라. V
    // 
    // 2번선택지는 나간다.      V
    system("cls");
    printf_s("현재 플레리어 무기는 %d강 입니다.\n", _Player.Weapon.GetEquipUp());

    printf_s("강화를 하시겠습니까.\n");
    printf_s("1. 강화.\n");
    printf_s("2. 나간다.\n");

    int Select = _getch();

    switch (Select)
    {
    case '1':
    {
        if (30 <= _Player.Weapon.GetEquipUp())
        {
            printf_s("30강 이상은 강화할 수 없습니다\n");
            int temp = _getch();
            break;
        }

        // 무기를 강화하는 함수를 만들고 호출하기
        _Player.Weapon.WeaponGradeUP();
        int temp = _getch();
        break;
    }
    case '2':
        return;
    default:
        break;
    }



    // 2.번
    // 1강부터 10강까지는 실패해도 강화수치가 떨어지지 않습니다.
    // 10강부터 20강까지는 실패하면 강화수치가 5씩 떨어집니다.
    // 20강부터 30강까지는 실패하면 강화수치가 0이 됩니다.
    // 강화확률은 마음대로
}

void Town::Heal(Player& _Player)
{
    printf_s("플레이어는 치료되었습니다.");
    int Select = _getch();
}

void Town::In(Player& _Player)
{
    while (true)
    {
        _Player.StatusRender();
        printf_s("마을에서 무엇을 하시겠습니까.\n");
        printf_s("1. 강화.\n");
        printf_s("2. 치료.\n");
        printf_s("3. 나간다.\n");
        int Select = _getch();

        switch (Select)
        {
        case '1':
            WeaponUp(_Player);
            break;
        case '2':
            Heal(_Player);
            break;
        case '3':
            return;
        default:
            break;
        }

        system("cls");
    }

}
