#include "Weapon.h"
#include "ProbUnit.h"
#include <iostream>

void Weapon::WeaponGradeUP()
{
    // 화면 초기화
    system("cls");

    //1강부터 10강까지는 실패해도 강화수치가 떨어지지 않습니다.     V
        // 10강부터 20강까지는 실패하면 강화수치가 5씩 떨어집니다.    V
        // 20강부터 30강까지는 실패하면 강화수치가 0이 됩니다.      V
        // 강화확률은 마음대로   V
    int CurWeaponGrade = GetEquipUp();
    ProbUnit NewProb;
    

    if (10 > CurWeaponGrade && 0 <= CurWeaponGrade)
    {
        NewProb.ProbReset(100);
        int Prob0To10 = NewProb.GetProb();

        //강화 확률 50퍼
        if (50 > Prob0To10)
        {
            // 1이면 강화 성공
            SetEquipgrade(++EquipUp);
            printf_s("%d강 -> %d강 강화 성공! \n", EquipUp-1, EquipUp);
        }
        else
        {
            printf_s("강화 실패..\n");
        }

    }
    else if (20 > CurWeaponGrade && 10 <= CurWeaponGrade)
    {
        
        NewProb.ProbReset(100);
        int Prob10To20 = NewProb.GetProb();

        // 강화 확률 30퍼
        if (30 > Prob10To20)
        {
            // 1이면 강화 성공
            SetEquipgrade(++EquipUp);
            printf_s("%d강 -> %d강 강화 성공! \n", EquipUp - 1, EquipUp);
        }
        else
        {
            // 실패 시 강화수치 강등 코드
            SetEquipGradeDown(5);
            printf_s("강화 실패..\n");
        }


    }
    else if (30 > CurWeaponGrade && 20 <= CurWeaponGrade)
    {
        //printf_s("20강부터 30강입니다.\n");
        NewProb.ProbReset(100);
        int Prob20To30 = NewProb.GetProb();

        // 강화확률10퍼
        if (10 > Prob20To30)
        {
            // 1이면 강화 성공
            SetEquipgrade(++EquipUp);
            printf_s("%d강 -> %d강 강화 성공! \n", EquipUp - 1, EquipUp);
        }
        else
        {
            // 실패시 강화수치 강등 코드
            SetEquipgrade(0);
            printf_s("강화 실패..\n");
            // 몇강에서 몇강 떨어졋는지 구현하는 코드

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