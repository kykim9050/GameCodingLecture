#include "Town.h"
#include <iostream>
#include <conio.h>
#include "Player.h"

void Town::WeaponUp(Player& _Player)
{
    // �����е��� �ǵ���� �ϴ� �κ��� ���� ���Դϴ�.

    // 1. �÷��̾��� ������ ��ȭ ���¸� �����ش�.    V
    // ���� �׷����� �������� ���δ� �����.    V
    // 1���������� ��ȭ        V
    //   30���� ������ �α�� ��ȭ�� �ȵȴٰ� �����. V
    // 
    // 2���������� ������.      V
    system("cls");
    printf_s("���� �÷����� ����� %d�� �Դϴ�.\n", _Player.Weapon.GetEquipUp());

    printf_s("��ȭ�� �Ͻðڽ��ϱ�.\n");
    printf_s("1. ��ȭ.\n");
    printf_s("2. ������.\n");

    int Select = _getch();

    switch (Select)
    {
    case '1':
    {
        if (30 <= _Player.Weapon.GetEquipUp())
        {
            printf_s("30�� �̻��� ��ȭ�� �� �����ϴ�\n");
            int temp = _getch();
            break;
        }

        // ���⸦ ��ȭ�ϴ� �Լ��� ����� ȣ���ϱ�
        _Player.Weapon.WeaponGradeUP();
        int temp = _getch();
        break;
    }
    case '2':
        return;
    default:
        break;
    }



    // 2.��
    // 1������ 10�������� �����ص� ��ȭ��ġ�� �������� �ʽ��ϴ�.
    // 10������ 20�������� �����ϸ� ��ȭ��ġ�� 5�� �������ϴ�.
    // 20������ 30�������� �����ϸ� ��ȭ��ġ�� 0�� �˴ϴ�.
    // ��ȭȮ���� �������
}

void Town::Heal(Player& _Player)
{
    printf_s("�÷��̾�� ġ��Ǿ����ϴ�.");
    int Select = _getch();
}

void Town::In(Player& _Player)
{
    while (true)
    {
        _Player.StatusRender();
        printf_s("�������� ������ �Ͻðڽ��ϱ�.\n");
        printf_s("1. ��ȭ.\n");
        printf_s("2. ġ��.\n");
        printf_s("3. ������.\n");
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
