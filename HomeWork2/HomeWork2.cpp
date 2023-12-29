// HomeWork2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Test(int _Value0, int _Value1, int _Value2, int _Value3)
{
    //int* Ptr0 = &_Value0;
    //int* Ptr1 = &_Value1;
    //int* Ptr2 = &_Value2;
    //int* Ptr3 = &_Value3;

    //// 8바이트씩 늘어나네
    //__int64 Address0 = reinterpret_cast<__int64>(Ptr0);
    //__int64 Address1 = reinterpret_cast<__int64>(Ptr1);
    //__int64 Address2 = reinterpret_cast<__int64>(Ptr2);
    //__int64 Address3 = reinterpret_cast<__int64>(Ptr3);

    __int64 Address0 = reinterpret_cast<__int64>(&_Value0);
    __int64 Address1 = reinterpret_cast<__int64>(&_Value1);
    __int64 Address2 = reinterpret_cast<__int64>(&_Value2);
    __int64 Address3 = reinterpret_cast<__int64>(&_Value3);

    //int a = 0;
}

int main()
{
    //int num1 = 1;
    //int num2 = 2;
    //int num3 = 3;
    //int num4 = 4;

    //Test(num1,num2,num3,num4);
    Test(10, 20, 30, 40);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
