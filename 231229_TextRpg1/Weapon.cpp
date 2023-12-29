#include "Weapon.h"
#include "ProbUnit.h"
#include <iostream>

void Weapon::WeaponGradeUP()
{
    // ȭ�� �ʱ�ȭ
    system("cls");

    //1������ 10�������� �����ص� ��ȭ��ġ�� �������� �ʽ��ϴ�.     V
        // 10������ 20�������� �����ϸ� ��ȭ��ġ�� 5�� �������ϴ�.    V
        // 20������ 30�������� �����ϸ� ��ȭ��ġ�� 0�� �˴ϴ�.      V
        // ��ȭȮ���� �������   V
    int CurWeaponGrade = GetEquipUp();
    ProbUnit NewProb;
    

    if (10 > CurWeaponGrade && 0 <= CurWeaponGrade)
    {
        NewProb.ProbReset(100);
        int Prob0To10 = NewProb.GetProb();

        //��ȭ Ȯ�� 50��
        if (50 > Prob0To10)
        {
            // 1�̸� ��ȭ ����
            SetEquipgrade(++EquipUp);
            printf_s("%d�� -> %d�� ��ȭ ����! \n", EquipUp-1, EquipUp);
        }
        else
        {
            printf_s("��ȭ ����..\n");
        }

    }
    else if (20 > CurWeaponGrade && 10 <= CurWeaponGrade)
    {
        
        NewProb.ProbReset(100);
        int Prob10To20 = NewProb.GetProb();

        // ��ȭ Ȯ�� 30��
        if (30 > Prob10To20)
        {
            // 1�̸� ��ȭ ����
            SetEquipgrade(++EquipUp);
            printf_s("%d�� -> %d�� ��ȭ ����! \n", EquipUp - 1, EquipUp);
        }
        else
        {
            // ���� �� ��ȭ��ġ ���� �ڵ�
            SetEquipGradeDown(5);
            printf_s("��ȭ ����..\n");
        }


    }
    else if (30 > CurWeaponGrade && 20 <= CurWeaponGrade)
    {
        //printf_s("20������ 30���Դϴ�.\n");
        NewProb.ProbReset(100);
        int Prob20To30 = NewProb.GetProb();

        // ��ȭȮ��10��
        if (10 > Prob20To30)
        {
            // 1�̸� ��ȭ ����
            SetEquipgrade(++EquipUp);
            printf_s("%d�� -> %d�� ��ȭ ����! \n", EquipUp - 1, EquipUp);
        }
        else
        {
            // ���н� ��ȭ��ġ ���� �ڵ�
            SetEquipgrade(0);
            printf_s("��ȭ ����..\n");
            // ����� � ������� �����ϴ� �ڵ�

        }
    }
    else
    {
        return;
    }


}

void Weapon::SetEquipGradeDown(int _DownVal)
{
    if (0 >= (GetEquipUp() - _DownVal))
    {
        SetEquipgrade(0);
    }
    else
    {
        SetEquipgrade(GetEquipUp() - _DownVal);
    }

    return;
}